#include "levels.h"
#include "ball.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include "blocks.h"
#include <QScreen>
#include <QPushButton>
#include <QGraphicsTextItem>
#include <QFont>
#include "game.h"
#include "ball.h"
levels::levels(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(0, 0, 67*3*currLevel, 600); // 600 vertical
    scene->setBackgroundBrush(QBrush(Qt::black));
    setScene(scene);

    // Disable scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Resize the view to match the scene size
    setFixedSize(scene->width(), scene->height());
}
void levels::hidecurrentscene() {
    hide();
}

void levels:: startlevel(){
    scene->clear();

    scene->setSceneRect(0, 0, 67 * 3 * currLevel, 600);
    ball *b= new ball(":/Ball.png");
    b->setPos((67*3*currLevel)/2,500);
    scene->addItem(b);
    player *p= new player();
    p->setPos((((67*3*currLevel)/2)-100)/2,575);
    scene->addItem(p);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    h=new health();
    h->setPos(scene->width()-90, scene->height()-120);
    scene->addItem(h);
    s=new score();
    QGraphicsTextItem *levelll = new QGraphicsTextItem();
    levelll->setPlainText("Level: " + QString::number(currLevel));
    levelll->setDefaultTextColor(Qt::white);
    levelll->setFont(QFont("times", 14));
    levelll->setPos(scene->width()-90, scene->height()-70);
    scene->addItem(levelll);

    createbl();
}

void levels::createbl(){
    QColor colors[] = {Qt::red, Qt::green, Qt::yellow, Qt::blue, Qt::cyan, Qt::magenta};
    for(int i=0;i<(currLevel*3);i++){//change according to level
        for(int j=0;j<(currLevel*2);j++){
            QColor color = colors[(i + j) % 6];
            blocks *block = new blocks(color);
            block->setPos(i*64,j*64);
            scene ->addItem(block);
        }
    }
}


