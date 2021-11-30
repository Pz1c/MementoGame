#ifndef QMGBASE_H
#define QMGBASE_H

#include <QDebug>

class QMGBase : public QObject
{
    Q_OBJECT

public:
    explicit QMGBase(QObject *parent = nullptr);
    virtual ~QMGBase();

    virtual QString json();



private:
    int _id;
    static int GLOBAL_ID;
};

#endif // QMGBASE_H
