#include "healthscore.h"
#include <QFont>
#include <QMessageBox>
#include "game.h"
#include <QWidget>

 extern Game *g;
healthscore::healthscore() {
    health =3;
    setPlainText("health: "+QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",12));
    score=0;
    setPlainText("score: "+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",12));
}
void healthscore::decrease_health(){
    health--;
    setPlainText("health: "+QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",12));

    if (health==0)
    {
         QMessageBox::critical(nullptr, "GAME OVER !","Your score is "+ QString::number(g->s->getscore()));
          g->clear();
         g->isGameOver();
    }
}

int healthscore::gethealth(){
    return health;
}
void healthscore::increase_score(){
    score++;
    setPlainText("score: "+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",12));
}
int healthscore::getscore(){
    return score;
}
