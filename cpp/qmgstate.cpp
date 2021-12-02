#include "qmgstate.h"

QMGState::QMGState(QObject *parent) :
    QMGBase(parent)
{
    _status = 0;
}

QMGState::~QMGState() {
    qDebug() << "QMGState::~QMGState";
}

QString QMGState::json() const {
    return QString("{\"id\":%1,\"state\":\"%2\"}").arg(QString::number(_id), QString::number(_status));
}

int QMGState::status() const
{
    return _status;
}

void QMGState::setStatus(int newStatus)
{
    _status = newStatus;
}
