#ifndef QMGCHILD2_H
#define QMGCHILD2_H

#include <QObject>
#include <QDebug>
#include "qmgchild1.h"
#include "qmgchild2.h"

class QMGCard : public QMGChild1, QMGChild2
{
    Q_OBJECT

public:
    explicit QMGCard(QObject *parent = nullptr);
    ~QMGCard();

signals:
    
public slots:

protected slots:
    
protected:

private:
    

};

#endif // QMGCHILD2_H
