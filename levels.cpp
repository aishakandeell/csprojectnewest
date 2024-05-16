#include "levels.h"
#include "ball.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include "blocks.h"
#include <QScreen>
#include "game.h"
#include "ball.h"
levels::levels(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(0, 0, 67*3*currLevel, 800); // 600 horizontally, 800 vertically
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

    scene->setSceneRect(0, 0, 67 * 3 * currLevel, 800);
    ball *b= new ball(":/Ball.png");
    b->setPos((67*3*currLevel)/2,700);
    scene->addItem(b);
    player *p= new player();
    p->setPos((((67*3*currLevel)/2)-100)/2,775);
    scene->addItem(p);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    h=new health();
    h->setPos(h->x(),h->y()+25);
    scene->addItem(h);
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


