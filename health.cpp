#include "health.h"
#include <QFont>
#include <QMessageBox>
#include <QPushButton>
#include "game.h"
#include "ball.h"
#include "score.h"
#include "levels.h"
#include "abilities.h"
extern game * Game;
extern levels*Levels;
extern bool ownshealth;
//extern int healthc=3;
health::health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    healthc=3;
    //display the text
    setPlainText("Health: " + QString::number(healthc));
    setDefaultTextColor(Qt::white);
    setFont(QFont("System",12));

}

void health::decrease() {
    qDebug() << "health decrease is called from funcdtion " ;
    qDebug() << "Current health: " << healthc;
    healthc--;
    qDebug() << "health after decrementing: " << healthc;
    setPlainText("Health: " + QString::number(healthc));

    if (healthc < 1) {
        QMessageBox msgbox;//starrt
        int playerscore=Levels->s->getscore();
        QString messagee="Your score is "+QString::number(playerscore);
        msgbox.setWindowTitle("You have no health left");
        msgbox.setText(messagee);
        //add button to go to level 1

        QPushButton *nextlevelbutton = new QPushButton("Go To Level 1");
        connect(nextlevelbutton, &QPushButton::clicked, this, game::level1);//level1 function
        msgbox.addButton(nextlevelbutton, QMessageBox::AcceptRole);

        QPushButton *exitbutton = new QPushButton("Exit Game");
        connect(exitbutton, &QPushButton::clicked, this, game::exitgame);
        msgbox.addButton(exitbutton, QMessageBox::RejectRole);


        msgbox.exec();//end

    } else {
        // Create a new ball
        ball *Ball = new ball(":/Ball.png");
        Ball->setPos(300, 500);
        Levels->scene->addItem(Ball);
    }

    // Remove and delete the existing ball
    QList<QGraphicsItem *> items = Levels->scene->items();
    for (int i = 0; i < items.size(); ++i) {
        ball *Ball = dynamic_cast<ball *>(items[i]);
        if (Ball) {
            Levels->scene->removeItem(Ball);
            delete Ball;
            break;
        }
    }
}

int health::gethealth(){
    return healthc;
}
void health::sethealth(){
    healthc=healthc+2;
    setPlainText("Health: " + QString::number(healthc));
    ownshealth = false;
}
