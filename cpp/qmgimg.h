#ifndef QMGIMG_H
#define QMGIMG_H

#include <QObject>
#include <QDebug>
#include "qmgbase.h"

class QMGImg : public virtual QMGBase
{
    Q_OBJECT

public:
    explicit QMGImg(QObject *parent = nullptr);
    explicit QMGImg(const char *src, QObject *parent = nullptr);
    //explicit QMGChild1(const QString QObject *parent = nullptr);
    virtual ~QMGImg();
    virtual QString json();

protected:
    char* _src; // path to image file

};

#endif // QMGIMG_H
