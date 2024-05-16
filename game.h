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
};

#endif // GAME_H
