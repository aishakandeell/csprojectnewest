#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QMessageBox>

class health: public QGraphicsTextItem {
public:
    health(QGraphicsItem *parent = nullptr);
    void decrease();
    int gethealth();
    void sethealth(int n);
    void healthreset();
    int healthc;
private:
    //int healthc;
    QMessageBox* msg = new QMessageBox;
};


#endif // HEALTH_H
