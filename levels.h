#ifndef LEVELS_H
#define LEVELS_H

#include <QApplication>
#include "ball.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "score.h"
#include "health.h"
#include "player.h"


class levels:public QGraphicsView
{
public:
    levels(QWidget *parent=0);
    QGraphicsScene *scene;
    score *s;
    health *h;
    void startlevel();
    void genblocks(int gen);
    void createbl();
    void hidecurrentscene();

};

#endif // LEVELS_H
