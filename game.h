#ifndef GAME_H
#define GAME_H

extern int currLevel;
class game
{
public:
    game();
    bool allblocksremoved();
    static void nextlevel();
    static void exitgame();
    static void level1();
    static void level2();
    static void level3();
    static void level4();
    static void level5();
    static void ability();
};

#endif // GAME_H
