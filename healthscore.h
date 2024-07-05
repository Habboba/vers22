#ifndef HEALTHSCORE_H
#define HEALTHSCORE_H
#include <QGraphicsTextItem>

class healthscore : public QGraphicsTextItem
{
public:
    healthscore();
    void decrease_health();
    void increase_score();
    int getscore();
    int gethealth();
private:
    int health, score;
};

#endif // HEALTHSCORE_H
