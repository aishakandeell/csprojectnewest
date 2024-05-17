#include "abilities.h"
#include "qfont.h"
#include "qgraphicsitem.h"
#include "levels.h"

bool owns3x = false;
bool ownshealth = false;
extern levels* Levels;

bool activate3x = false;
bool activateslow = false;


abilities::abilities(): QObject() {}

void abilities::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Space )
    {
        if(owns3x)
        {
            activate3x = true;
            owns3x = false;
            QGraphicsTextItem* activated=new QGraphicsTextItem();
            activated->setPlainText("3x Balls Activated");
            activated->setDefaultTextColor(Qt::white);
            activated->setFont(QFont("System",12));
            activated->setPos(Levels->scene->width()-70, Levels->scene->height()-100);
            Levels->scene->addItem(activated);
        }
    }

    if(event->key()== Qt::Key_E)
    {
        if(ownshealth)
        {
            activateslow = true;
            ownshealth = false;
            QGraphicsTextItem* activated=new QGraphicsTextItem();
            activated->setPlainText("Slow Time Activated");
            activated->setDefaultTextColor(Qt::white);
            activated->setFont(QFont("System",12));
            activated->setPos(Levels->scene->width()-70, Levels->scene->height()-100);
            Levels->scene->addItem(activated);

        }
    }

}
