#ifndef BLOCKS_H
#define BLOCKS_H

#include <QGraphicsRectItem>
class blocks: public QGraphicsRectItem{

public:
    blocks(QColor color, QGraphicsItem* parent=nullptr);
};

#endif // BLOCKS_H
