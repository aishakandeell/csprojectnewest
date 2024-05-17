#include "player.h"

#include "QtGui/qevent.h"
#include <QBrush>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "game.h"
#include "levels.h"
extern levels*Levels;
player::player(const QString &imagePath, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(QPixmap(imagePath).scaled(100, 40), parent){
}

double player::getMidPoint(){
    return x()+pixmap().width()/2;
}

void player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left || event->key()== Qt::Key_A )
    {
        if(x()>0)
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right || event->key()== Qt::Key_D )
    {
        if(getMidPoint()+50<Levels->width())
            setPos(x()+10,y());
    }

}
