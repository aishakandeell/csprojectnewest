#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class player: public QObject, public QGraphicsPixmapItem{
public:

    player(const QString& imagePath, QGraphicsItem* parent=NULL);
    double getMidPoint();
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H
