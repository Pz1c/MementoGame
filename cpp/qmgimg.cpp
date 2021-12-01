#include "qmgimg.h"

QMGImg::QMGImg(QObject *parent) :
    QMGBase(parent), _src(nullptr)
{

}

QMGImg::QMGImg(const char *src, QObject *parent) : QMGBase(parent) {
    int ln = src ? std::strlen(src) : 0;
    _src = new char[ln + 1];
    if (ln > 0) {
        std::memcpy(_src, src, ln + 1);
    } else {
        _src[0] = '\0';
    }
}

QMGImg::~QMGImg() {
    qDebug() << "QMGImg::~QMGImg";
    if (_src) {
        delete [] _src;
    }
}

QString QMGImg::json() {
    return QString("{\"id\":%1,\"src\":\"%2\"}").arg(QString::number(_id), _src);
}
