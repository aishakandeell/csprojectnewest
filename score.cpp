#include "score.h"
#include <QFont>
#include <QMessageBox>
#include <QPushButton>
#include "game.h"
#include "score.h"
#include "levels.h"

extern game * Game;
extern levels*Levels;
int scorec = 0;

score::score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    //display the text
    setPlainText("Score: " + QString::number(scorec));
    setDefaultTextColor(Qt::white);
    setFont(QFont("System",12));
}

void score::increase(){
    qDebug() << "score increased is called from function " ;
    qDebug() << "Current score: " << scorec;
    scorec++;
    qDebug() << "score after incrementing: " << scorec;
    setPlainText("Score: " + QString::number(scorec));
}

int score::getscore(){
    return scorec;
}

