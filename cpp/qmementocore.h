#ifndef QMEMENTOCORE_H
#define QMEMENTOCORE_H

#include <QObject>
#include <QDebug>
#include <QList>
#include <QDir>

#include "qmgcard.h"

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

public slots:
    void startGame();
    void click(int card_idx);

protected slots:
    
protected:

private:
    QList<QMGCard *> _cards;
    int _score;
    //QString _pathToImgFolder;
    QStringList _allImgs;
    QString _fullPathToImgFolder;
};

#endif // QMEMENTOCORE_H
