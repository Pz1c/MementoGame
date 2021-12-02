#include "qmgcard.h"

QMGCard::QMGCard(QObject *parent) :
    QMGImg(parent), QMGState(parent)
{
    qDebug() << "QMGCard::QMGCard";
}

QMGCard::QMGCard(const char* src, QObject *parent) :
    QMGImg(src, parent), QMGState(parent)
{
    qDebug() << "QMGCard::QMGCard" << src;
}

QMGCard::QMGCard(const QMGCard& copy_from) {
    qDebug() << "QMGCard::QMGCard" << "copy_from" << copy_from.json();
    size_t ln = std::strlen(copy_from._src) + 1;
    if (_src) {
        delete [] _src;
    }
    _src = new char[ln];
    std::memcpy(_src, copy_from._src, ln);
    _status = copy_from._status;
    _id = copy_from._id;
}

QMGCard::QMGCard(QMGCard&& move_from) {
    qDebug() << "QMGCard::QMGCard" << "move_from" << move_from.json();
    if (_src) {
        delete [] _src;
    }
    _src = move_from._src;
    move_from._src = nullptr;
    _status = move_from._status;
    _id = move_from._id;
}

QMGCard& QMGCard::operator = (QMGCard assign_from) {
    std::swap(_src, assign_from._src);
    _status = assign_from._status;
    _id = assign_from._id;
    return *this;
}

QMGCard::~QMGCard() {
    qDebug() << "QMGCard::~QMGCard";
}

QString QMGCard::json() const {
    return QString("{\"id\":%1,\"status\":%2,\"src\":\"%3\"}").arg(QString::number(_id), QString::number(_status), _src);
}

bool QMGCard::checkEqual(const QMGCard &item) const {
    return strcmp(_src, item._src) == 0;
}
