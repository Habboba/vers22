#ifndef ENEMY_H
#define ENEMY_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Enemy: public QObject, public QGraphicsPixmapItem
{
public:
    Enemy();
private slots:
    void move();

};

#endif // ENEMY_H
