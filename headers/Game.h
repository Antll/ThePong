#ifndef GAME_H
#define GAME_H

#include "Controller.h"
#include "Display.h"

class UGame
{
public:
    UGame(UDisplay* Display);
    ~UGame();
    void Update();
private:
    UController* Player;
};

#endif // GAME_H
