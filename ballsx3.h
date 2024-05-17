#ifndef BALLSX3_H
#define BALLSX3_H

#include <QGraphicsRectItem>
#include <QObject>


class ballsx3:  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ballsx3(const QString& imagePath, QGraphicsItem* parent=nullptr);
    double getcenter();
    void blockcollision();
    void playercollision();

public slots:
    void move();
private:
    double moveX;
    double moveY;
};

#endif // BALLSX3_H
