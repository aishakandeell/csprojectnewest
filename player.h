#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class player: public QGraphicsRectItem{
public:

    player(QGraphicsItem* parent=NULL);
    double getMidPoint();
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H
