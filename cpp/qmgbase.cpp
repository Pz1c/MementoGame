#include "qmgbase.h"

int QMGBase::GLOBAL_ID = 0;

QMGBase::QMGBase(QObject *parent) :
    QObject(parent)
{
    _id = ++QMGBase::GLOBAL_ID;
}

QMGBase::~QMGBase() {
    
}

QString QMGBase::json() {
    return QString("{\"id\":%1}").arg(QString::number(_id));
}
