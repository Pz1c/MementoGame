#ifndef QMGCARD_H
#define QMGCARD_H

#include <QObject>
#include <QDebug>
#include "qmgimg.h"
#include "qmgstate.h"

class QMGCard : public QMGImg, public QMGState
{
    Q_OBJECT

public:
    explicit QMGCard(QObject *parent = nullptr);
    explicit QMGCard(const char* src, QObject *parent = nullptr);
    explicit QMGCard(const QMGCard& copy_from);
    explicit QMGCard(QMGCard&& move_from);
    QMGCard& operator = (QMGCard assign_from);
    ~QMGCard();
    QString json() override;
    

};

#endif // QMGCARD_H
