#include "enemy.h"
#include "game.h"
#include "player.h"
#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <cstdlib>
#include <QList>
#include <QDebug>

extern Game *g;
Enemy::Enemy(): QObject(), QGraphicsPixmapItem() {
    setPos(rand() % 700,0);
    setPixmap(QPixmap(":/Chicken png.webp").scaled(50,50));

    QTimer *ti = new QTimer(this);
    connect(ti, SIGNAL(timeout()), this , SLOT(move()));
    ti->start(200);

}
void Enemy::move(){
    QList<QGraphicsItem*> coll=collidingItems();
    for (QGraphicsItem *ii : coll){
        if (typeid(*ii)==typeid(Player))
        {
            scene()->removeItem(this);
            delete this;
            g->h->decrease_health();
            return;
        }
    }
    setPos(x(), y()+10);
    qDebug()<<"Enemy is moving\n";

    if (pos().y()-pixmap().height()>600)
    {
        scene()->removeItem(this);
        delete this;
        qDebug()<<"The bullet is deleted.\n";
    }
}
