#ifndef QMEMENTOCORE_H
#define QMEMENTOCORE_H

#include <QObject>
#include <QDebug>
#include <QList>

#include "qmgcard.h"

class QMementoCore : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int score READ score NOTIFY scoreChanged)

public:
    explicit QMementoCore(QObject *parent = nullptr);
    ~QMementoCore();
    int score();

signals:
    void scoreChanged();
    void action(int idx, QString command);
    void gameStarted(QString card_model);

public slots:
    void startGame();
    void click(int card_idx);

protected slots:
    
protected:

private:
    QList<QMGCard *> _cards;
    int _score;
};

#endif // QMEMENTOCORE_H
