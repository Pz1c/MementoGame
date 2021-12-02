#include "qmementocore.h"

QMementoCore::QMementoCore(QObject *parent) :
    QObject(parent)
{
    _imgCurIdx = 0;

    // TODO move to params
    QString curr_dir = QDir::currentPath();
    _fullPathToImgFolder = "/../MementoGame/res/nw_portraits";
    qDebug() << "QMementoCore::QMementoCore" << curr_dir << _fullPathToImgFolder;

    QDir directory(QString("%1%2").arg(curr_dir, _fullPathToImgFolder));
    QStringList allImgs = directory.entryList(QStringList() << "*.png", QDir::Files);
    qDebug() << "QMementoCore::QMementoCore" << allImgs;
    foreach(QString file_name, allImgs) {
        QByteArray ba;
        ba.append(QString("file:///%1%2/%3").arg(curr_dir, _fullPathToImgFolder, file_name).toLocal8Bit());
        _allCard.append(new QMGCard(ba.data()));
        qDebug() << _allCard.last()->json();
    }
    qDebug() << "QMementoCore::QMementoCore" << "try shuffle";
    prepareImgArray();
    //emit ready();
    QTimer::singleShot(500, this, [this]{ emit this->ready(); });
}

QMementoCore::~QMementoCore() {
    foreach(QMGCard *c, _allCard) {
        delete c;
    }
    foreach(QMGCard *c, _cards) {
        delete c;
    }
}

int QMementoCore::score() {
    return _score;
}

void QMementoCore::startGame() {
    checkImgArray();
    fillGameImgArray();
    //
    _score = 0;
    emit scoreChanged(_score);

}

void QMementoCore::changeScore(int diff) {
    _score += diff;
    emit scoreChanged(_score);
}

void QMementoCore::click(int card_idx) {
    qDebug() << "QMementoCore::click" << card_idx  << _cards.size();
    if ((card_idx < 0) || (card_idx >= _cards.size())) {return ;}
    if (_cards.at(card_idx)->status() == MG_CARD_STATE_OPEN) {
        // nothing to do, card already oppennded
        return;
    }

    if (_openCard.size() >= 2) {
        foreach(int ci, _openCard) {
            emit action(ci, "close");
        }
        _openCard.clear();
        changeScore(MC_SCORE_PENALTY);
    }

    emit action(card_idx, "open");
    _openCard.append(card_idx);

    if (_openCard.size() == 2) {
        if (_cards.at(_openCard.at(0))->checkEqual(*_cards.at(card_idx))) {
            _openCard.clear();
            changeScore(MC_SCORE_BONUS);
        }
    }
}

void QMementoCore::fillGameImgArray() {
    qDebug() << "QMementoCore::fillGameImgArray" << _allCard.size() << _cards.size() << _imgCurIdx << MC_CARD_IN_GAME;
    foreach(QMGCard *c, _cards) {
        delete c;
    }
    _cards.clear();
    if (_allCard.empty()) {
        return;
    }

    int idx = 0;
    for(int i = _imgCurIdx, Ln = _imgCurIdx + MC_CARD_IN_GAME; i < Ln; ++i) {
        idx = (i == 0) ? 0 : QRandomGenerator::system()->bounded(0, _cards.size());
        _cards.insert(idx, new QMGCard(*_allCard.at(i)));
    }
    for(int i = _imgCurIdx, Ln = _imgCurIdx + MC_CARD_IN_GAME; i < Ln; ++i) {
        idx = QRandomGenerator::system()->bounded(0, _cards.size());
        _cards.insert(idx, new QMGCard(*_allCard.at(i)));
    }
    _imgCurIdx += MC_CARD_IN_GAME;
    // bad result on small array
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(_cards.begin(), _cards.end(), g);

    QString card_list = "[";
    for(int i = 0; i < MC_CARD_IN_GAME * 2; ++i) {
        if (i > 0) {
            card_list.append(",");
        }
        card_list.append(_cards.at(i)->json());
    }
    card_list.append("]");
    qDebug() << card_list;
    emit gameStarted(card_list);
}

void QMementoCore::checkImgArray() {
    qDebug() << "QMementoCore::checkImgArray" << _allCard.size() << _imgCurIdx << MC_CARD_IN_GAME;
    if (_allCard.size() < _imgCurIdx + MC_CARD_IN_GAME) {
        prepareImgArray();
    }
}

void QMementoCore::prepareImgArray() {
    qDebug() << "QMementoCore::prepareImgArray" << _allCard.size() << _imgCurIdx;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(_allCard.begin(), _allCard.end(), g);
    _imgCurIdx = 0;
}
