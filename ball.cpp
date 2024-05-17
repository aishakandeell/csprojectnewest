#include "ball.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QList>
#include <QDebug>
#include "score.h"
#include "game.h"
#include "blocks.h"
#include <QBrush>
#include "player.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QPushButton>
#include "levels.h"
extern levels*Levels;
extern game * Game;
//extern int levels=1;
ball::ball(const QString& imagePath, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(QPixmap(imagePath).scaled(35, 35), parent){
    moveX=0;
    moveY=-7;//it decreases by 7

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start((5-currLevel)*10);// change to variable according to level
}
double ball::getcenter(){
    return x() + pixmap().width() / 2.0;
}
void ball::blockcollision(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i) {
        blocks* block = dynamic_cast<blocks*>(colliding_items[i]);
        if (block) {
            Levels->s->increase();
            qDebug() << "Ball collided with block";
            qDebug()<<"position if block"<<pos().y();
            // Remove block from scene if it exists in the scene
            if (block->scene()) {
                qDebug() << "block removed from scene";
                Levels->scene->removeItem(block);
                delete block;
            }
            moveY = -moveY;
            //if it collides from the side chanve movex
            if (pos().x() > (block->pos().x() + 10) || block->pos().x() > (pos().x()+10) ){
                moveX = - moveX;
            }
            return;
        }
    }
}

void ball::playercollision(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i) {
        player* Player = dynamic_cast<player*>(colliding_items[i]);
        if (Player) {
            qDebug()<<"position if player"<<pos().y();
            moveY = -moveY;
            moveX=(moveX+getcenter()-Player->getMidPoint())/10;
            return;
        }
    }
}
void ball::move(){
    double height = Levels->height();
    blockcollision();
    playercollision();
    if (pos().y()>height){
        qDebug()<<"height is "<<pos().y();
    }
    // Handle out of bounds and continue movement
    if (pos().y()>height){///change to height
        qDebug()<<pos().y();
        qDebug() << "health decrease is called " ;
        Levels->h->decrease();//recheck when health decreases
        moveY = -moveY;
    }

    if (pos().y() <= 0) {
        moveY = -moveY; // Reverse vertical direction
    }
    if (pos().x() <= 0 || pos().x() >= Levels->width()) {
        moveX = -moveX; // Reverse horizontal direction
    }
    if (Game->allblocksremoved()) {
        qDebug() << "Player wins!";
        if (currLevel<=5){
            QMessageBox msgbox;
            msgbox.setWindowTitle("Level Over");
            msgbox.setText("You've completed the level.");
            msgbox.addButton(QMessageBox::Close);
            QPushButton *nextLevelButton = new QPushButton("Next Level");
            connect(nextLevelButton, &QPushButton::clicked, this, game::nextlevel);//next level function
            msgbox.addButton(nextLevelButton, QMessageBox::AcceptRole);
            QPushButton *abilityShop = new QPushButton("Buy Abilities");
            connect(abilityShop, &QPushButton::clicked, this, game::ability);//next level function
            msgbox.addButton(abilityShop, QMessageBox::AcceptRole);
            msgbox.exec();
            delete this;
        }
        else{
            QMessageBox msgboxx;
            int playerscore=Levels->s->getscore();
            QString message="Congratulations! You Have Completed All Levels. Your score is "+ QString::number(playerscore);
            msgboxx.setWindowTitle("You Have Won");
            msgboxx.setText(message);
            QPushButton *exitbuttonn = new QPushButton("Exit Game");
            connect(exitbuttonn, &QPushButton::clicked, this, game::exitgame);
            msgboxx.addButton(exitbuttonn, QMessageBox::RejectRole);

            msgboxx.exec();
        }
    }
    moveBy(moveX,moveY);
}
