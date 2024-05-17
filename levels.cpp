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
#include "abilitiesshop.h"
#include "abilities.h"
extern bool ownslow;
levels::levels(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(0, 0, 65*3*currLevel, 35*2*currLevel+500); // 600 vertical
    //setBackgroundBrush(QBrush(QImage(":/Background.jpg").scaled(65*3*currLevel,35*2*currLevel+400)));
    setBackgroundBrush(QBrush(Qt::black));
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

    scene->setSceneRect(0, 0, scene->width(), scene->height());
    ball *b= new ball(":/Ball.png");
    b->setPos((scene->width()/2),scene->height()-100);
    scene->addItem(b);
    player *p= new player(":/Player.png");
    p->setPos((((scene->width())/2)-100)/2,scene->height()-25);
    scene->addItem(p);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    s=new score();
    s->setPos(scene->width()-80, scene->height()-80);
    scene->addItem(s);
    h=new health();
    qDebug()<<"ownslow"<<ownslow;
    if(ownslow==true){
        h->sethealth();
    }
    h->setPos(scene->width()-80, scene->height()-100);
    scene->addItem(h);
    QGraphicsTextItem *levelll = new QGraphicsTextItem();
    levelll->setPlainText("Level: " + QString::number(currLevel));
    levelll->setDefaultTextColor(Qt::white);
    levelll->setFont(QFont("System", 12));
    levelll->setPos(scene->width()-80, scene->height()-120);
    scene->addItem(levelll);

    createbl();
}

void levels::createbl(){
    QColor colors[] = {QColorConstants::Svg::darkviolet, QColorConstants::Svg::slateblue, QColorConstants::Svg::fuchsia, QColorConstants::Svg::mediumslateblue, QColorConstants::Svg::midnightblue, QColorConstants::Svg::violet};
    for(int i=0;i<(currLevel*3);i++){//change according to level
        for(int j=0;j<(currLevel*2);j++){
            QColor color = colors[(i + j) % 6];
            blocks *block = new blocks(color);
            block->setPos(i*64,j*64);
            scene ->addItem(block);
        }
    }
}


