#ifndef ABILITIES_H
#define ABILITIES_H

#include "qevent.h"
extern bool own3x;
extern bool ownslow;
extern bool activate3x;
extern bool activateslow;

class abilities: public QObject
{
public:
    abilities();
    void keyPressEvent(QKeyEvent * event);
    bool getOwn();
};

#endif // ABILITIES_H
