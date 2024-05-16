#include "blocks.h"
#include <QBrush>

blocks::blocks(QColor color, QGraphicsItem* parent): QGraphicsRectItem(parent){

    setRect(0,0,60,30);
    QBrush brush(color);
    setBrush(brush);
}
