#ifndef QMGSTATE_H
#define QMGSTATE_H

#include <QObject>
#include <QDebug>
#include "qmgbase.h"

class QMGState : public virtual QMGBase
{
    Q_OBJECT

public:
    explicit QMGState(QObject *parent = nullptr);
    virtual ~QMGState();
    virtual QString json();

protected:
    int _status;

private:
    

};

#endif // QMGSTATE_H
