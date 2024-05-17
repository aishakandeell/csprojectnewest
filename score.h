#ifndef SCORE_H
#define SCORE_H
#include "qgraphicsitem.h"
extern int scorec;
class score : public QGraphicsTextItem
{
public:
    score(QGraphicsItem *parent = nullptr);
    void increase();
    int getscore();
    void setscore(int n);
};

#endif // SCORE_H
