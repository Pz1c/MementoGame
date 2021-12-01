#include "qmementocore.h"

QMementoCore::QMementoCore(QObject *parent) :
    QObject(parent)
{
    // create pool
    for(int i = 0; i < 99; ++i) {
        _cards.append(new QMGCard());
    }

    // TODO move to params
    _fullPathToImgFolder = QString("%1../../MementoGame/res/nw_portraits").arg(QDir::currentPath());
    QDir directory(_fullPathToImgFolder);
    _allImgs = directory.entryList(QStringList() << "*.tga", QDir::Files);
    qDebug() << _allImgs;
}

QMementoCore::~QMementoCore() {
    foreach(QMGCard *c, _cards) {
        delete c;
    }
    _cards.clear();
}

int QMementoCore::score() {
    return _score;
}

void QMementoCore::startGame() {

}

void QMementoCore::click(int card_idx) {
    qDebug() << "QMementoCore::click" << card_idx;
}
