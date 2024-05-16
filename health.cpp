#include "health.h"
#include <QFont>
#include <QMessageBox>
#include "game.h"
#include "ball.h"
#include "score.h"
#include "levels.h"
extern game * Game;
extern levels*Levels;
health::health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    healthc=3;
    //display the text
    setPlainText("Health: " + QString::number(healthc));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",14));

}
void health::decrease() {
    qDebug() << "Current health: " << healthc;
    healthc--;
    qDebug() << "health after decrementing: " << healthc;
    setPlainText("Health: " + QString::number(healthc));

    if (healthc < 1) {
        msg->setWindowTitle("You have no health left"); // Set the window title
        msg->exec();
        //game->scene->clear();
    } else {
        // Create a new ball
        ball *Ball = new ball(":/Ball.png");
        Ball->setPos(300, 700);
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
