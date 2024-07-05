#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "healthscore.h"

class Game : public QGraphicsScene
{
public:
    Game();
    QGraphicsScene *scene;
    Player *pl;
    healthscore* h, *s;
    void isGameOver();
private slots:
    void createEnemy();
};

#endif // GAME_H
