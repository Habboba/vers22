#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include<QTimer>
#include<QObject>
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include <QList>
#include <QMediaPlayer>
#include <QtMultimedia/QMediaPlayer>
#include <QUrl>
#include <QAudioOutput>

extern Game *g;
Bullet::Bullet(int x, int y, int w, int h) :QGraphicsPixmapItem(QPixmap(":/laser.png").scaled(w,h)) {
    setPos(x,y);
    QTimer *t=new QTimer();
    connect(t, SIGNAL(timeout()),this, SLOT(move()));
    t->start(50);
}

void Bullet::move(){
    // Game *g;
    QList<QGraphicsItem*> coll=collidingItems();
    for (QGraphicsItem *ii : coll){
        if (typeid(*ii)==typeid(Enemy))
        {

            g->s->increase_score();
            scene()->removeItem(ii);
            scene()->removeItem(this);

            QAudioOutput* mainthemeoutput = new QAudioOutput();
            mainthemeoutput ->setVolume(50);
            QMediaPlayer* maintheme = new QMediaPlayer();
            maintheme ->setAudioOutput(mainthemeoutput);
            maintheme->setSource(QUrl(":/box-crash.mp3"));
            maintheme->play();
            delete ii;
            delete this;

            return;
        }
    }
    setPos(x(), y()-30);
    if (pos().y()-pixmap().height()<-600)
    {
        scene()->removeItem(this);
        delete this;
    }

}
