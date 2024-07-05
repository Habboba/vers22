#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include<QObject>
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(int x, int y, int w, int h);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void createEnemy();
};

#endif // PLAYER_H
