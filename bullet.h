#ifndef BULLET_H
#define BULLET_H
#include <QObject>
#include <QGraphicsRectItem>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(int x, int y, int w, int h);
private slots:
    void move();
};

#endif // BULLET_H
