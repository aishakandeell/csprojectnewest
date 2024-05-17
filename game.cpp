#include "game.h"
#include "abilitiesshop.h"
#include "levels.h"
#include "blocks.h"
#include "ball.h"
#include "health.h"

extern int currLevel=0;
extern levels*Levels;
game::game(){}

void game::nextlevel(){

    currLevel++;

    if (Levels)
        delete Levels;
    Levels = new levels(); // Initialize Levels
    Levels->show();
    Levels->startlevel();
}
void game::level1(){
    currLevel=1;
    if (Levels)
        delete Levels;
    Levels = new levels(); // Initialize Levels
    Levels->show();
    Levels->startlevel();
}
void game::level2(){
    currLevel=2;
    if (Levels)
        delete Levels;
    Levels = new levels(); // Initialize Levels
    Levels->show();
    Levels->startlevel();
}
void game::level3(){
    currLevel=3;
    if (Levels)
        delete Levels;
    Levels = new levels(); // Initialize Levels
    Levels->show();
    Levels->startlevel();
}
void game::level4(){
    currLevel=4;
    if (Levels)
        delete Levels;
    Levels = new levels(); // Initialize Levels
    Levels->show();
    Levels->startlevel();
}
void game::level5(){
    currLevel=5;
    if (Levels)
        delete Levels;
    Levels = new levels(); // Initialize Levels
    Levels->show();
    Levels->startlevel();
}
void game::exitgame(){
    if (Levels) {
        Levels->hide();
        delete Levels;
        Levels = nullptr;
    }
}

void game::ability(){
    if(Levels) {
        delete Levels;
    }
    abilitiesShop* aS = new abilitiesShop();
    aS->show();
}

bool game::allblocksremoved(){
    QList<QGraphicsItem *> items = Levels->scene->items();
    for (int i = 0; i < items.size(); ++i) {
        if (dynamic_cast<blocks *>(items[i])) {
            // If any block is found, return false
            return false;
        }
    }
    // If no blocks are found, return true
    return true;
}
