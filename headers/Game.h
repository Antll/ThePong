#ifndef GAME_H
#define GAME_H

#include "Controller.h"
#include "Display.h"
#include "Ball.h"
#include <math.h>

class UGame
{
public:
    UGame(UDisplay* Display);
    ~UGame();
    void Update();
    
private:
    UController* Player;
    UController* TwinPlayer;
    UBall* Ball;
    
    bool IsBallOverlapedWithController(UBall* Ball, UController* Controller);
};

#endif // GAME_H
