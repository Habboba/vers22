#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QtMultimedia/QMediaPlayer>
#include <QUrl>
#include <QAudioOutput>
#include <QLabel>
#include <QPixmap>

Player::Player(int x, int y, int w, int h){
    setPixmap(QPixmap(":/ship.png").scaled(w,h));
    setPos(x,y);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}
void Player::keyPressEvent(QKeyEvent *event){
    if (event->key()== Qt::Key_Right){
        if (x()+100<800)
            setPos(x()+15,y());
    }
    else if (event->key()== Qt::Key_Left){
        if (x()>0)
            setPos(x()-15,y());
    }
    else if (event->key()== Qt::Key_Space){
        Bullet *b =new Bullet(x()+45, y()-50,5,50);
        scene()->addItem(b);
        QAudioOutput* mainthemeoutput = new QAudioOutput();
        mainthemeoutput ->setVolume(50);
        QMediaPlayer* maintheme = new QMediaPlayer();
        maintheme ->setAudioOutput(mainthemeoutput);
        maintheme->setSource(QUrl("qrc:/new/prefix1/resources/080886_bullet-39738.mp3"));
        maintheme ->play();
    }

}
void Player::createEnemy(){
    Enemy *e = new Enemy();
    scene()->addItem(e);
}

