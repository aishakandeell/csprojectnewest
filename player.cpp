#include "player.h"

#include "QtGui/qevent.h"
#include <QBrush>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "game.h"

player::player(QGraphicsItem *parent){
    setRect(0,0,100,10);
    QBrush brush(Qt::white);
    setBrush(brush);
}

double player::getMidPoint(){
    return x()+rect().width()/2;
}

void player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0)
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)
    {
        if(x()+80<67 * 3 * currLevel)
            setPos(x()+10,y());
    }

}
