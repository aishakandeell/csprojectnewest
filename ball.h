#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>
#include <QObject>


class ball:  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ball(const QString& imagePath, QGraphicsItem* parent=nullptr);
    double getcenter();
    void blockcollision();
    void playercollision();

public slots:
    void move();
private:
    double moveX;
    double moveY;
};

#endif // BALL_H
