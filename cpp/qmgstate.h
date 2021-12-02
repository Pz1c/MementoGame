#ifndef QMGSTATE_H
#define QMGSTATE_H

#include <QObject>
#include <QDebug>
#include "qmgbase.h"

#define MG_CARD_STATE_CLOSE 0
#define MG_CARD_STATE_OPEN 1

class QMGState : public virtual QMGBase
{
    Q_OBJECT

public:
    explicit QMGState(QObject *parent = nullptr);
    virtual ~QMGState();
    virtual QString json() const;

    int status() const;

    void setStatus(int newStatus);

protected:
    int _status;

private:
    

};

#endif // QMGSTATE_H
