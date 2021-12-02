#ifndef QMEMENTOCORE_H
#define QMEMENTOCORE_H

#include <QObject>
#include <QDebug>
#include <QList>
#include <QDir>
#include <algorithm>
#include <random>
#include <QTimer>
#include <QRandomGenerator>

#include "qmgcard.h"

#define MC_CARD_IN_GAME 50
#define MC_SCORE_BONUS 2
#define MC_SCORE_PENALTY -1

class QMementoCore : public QObject
{
    Q_OBJECT

public:
    explicit QMementoCore(QObject *parent = nullptr);
    ~QMementoCore();
    int score();

signals:
    void scoreChanged(int score);
    void action(int idx, QString command);
    void gameStarted(QString card_model);
    void ready();

public slots:
    void startGame();
    void click(int card_idx);

protected:
    void prepareImgArray();
    void checkImgArray();
    void fillGameImgArray();
    void changeScore(int diff);

private:
    int _score;
    int _imgCurIdx;
    QList<int> _openCard;
    QList<QMGCard *> _cards;
    QList<QMGCard *> _allCard;
    QString _fullPathToImgFolder;
};

#endif // QMEMENTOCORE_H
