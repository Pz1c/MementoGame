#ifndef QMGCHILD1_H
#define QMGCHILD1_H

#include <QObject>
#include <QDebug>
#include "qmgbase.h"

class QMGChild1 : public QMGBase
{
    Q_OBJECT

public:
    explicit QMGChild1(QObject *parent = nullptr);
    //explicit QMGChild1(const QString QObject *parent = nullptr);
    virtual ~QMGChild1();

protected:
    QString _scr; // path to image file

};

#endif // QMGCHILD1_H
