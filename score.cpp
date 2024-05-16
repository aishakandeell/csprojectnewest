#include "score.h"
int scoree=0;
score::score() {}
void score::increase(){
    scoree++;
}
int score::getscore(){
    return scoree;
}
