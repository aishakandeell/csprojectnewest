#include "player.h"

#include "QtGui/qevent.h"
#include <QBrush>
#include <QGraphicsScene>
#include <QKeyEvent>

player::player(QGraphicsItem *parent){
    // draw rect
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
        if(x()+80<800)
            setPos(x()+10,y());
    }

}
