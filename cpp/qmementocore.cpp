#include "qmementocore.h"

QMementoCore::QMementoCore(QObject *parent) :
    QObject(parent)
{
    // create pool
    for(int i = 0; i < 99; ++i) {
        _cards.append(new QMGCard());
    }
}

QMementoCore::~QMementoCore() {
    foreach(QMGCard *c, _cards) {
        delete c;
    }
    _cards.clear();
}

void QMementoCore::startGame() {

}

void QMementoCore::click(int card_idx) {

}
