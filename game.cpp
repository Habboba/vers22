#include "game.h"
#include "player.h"
#include <QGraphicsScene>
#include <QObject>
#include "enemy.h"
#include <QTimer>
#include "healthscore.h"
#include <QGraphicsItem>

Game::Game() {
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
   //setBackgroundBrush(QBrush(QImage(":/galaxmap.png").scaled(800,600)));

    pl=new Player(0,0,100,100);
    pl->setPos((width()/2)-50, height()-(pl->pixmap().height()));
    addItem(pl);

    s=new healthscore();
    addItem(s);
    h=new healthscore();
    h->setPos(0,25);
    addItem(h);

    QTimer *timer =new QTimer();
    QObject :: connect(timer , SIGNAL(timeout()), pl , SLOT(createenemy()));
    timer->start(2000);
}

void Game::createEnemy(){
    Enemy *e = new Enemy();
    addItem(e);
}
void Game::isGameOver()
{
    if (h->gethealth() <= 0) {

        clear();
        QGraphicsTextItem *gameOverText = new QGraphicsTextItem("Game Over");
        QFont gameOverFont("times", 30);
        gameOverText->setFont(gameOverFont);
        gameOverText->setDefaultTextColor(QColor(255, 192, 203));
        gameOverText->setPos(300, 250);
        addItem(gameOverText);
    }
}
