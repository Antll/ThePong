#ifndef GAME_H
#define GAME_H

#include "Controller.h"
#include "Display.h"
#include "Ball.h"
#include <math.h>
#include "DebugLine.h"
#include "ErrorHandling.h"
#include "AIController.h"

class UGame
{
public:
    UGame(UDisplay* Display);
    ~UGame();
    void Update();
    
private:
    UController* Player;
    UAIController* TwinPlayer;
    UBall* Ball;
    enum OBJECTS 
    {
        PLAYER,
        TWIN_PLAYER,
        WALL,
        WALL_LEFT,
        WALL_RIGHT
    };
    
    enum DIRECTION 
    {
        LEFT,
        RIGHT
    };
    
    bool IsBallOverlapedWithController(UBall* Ball, UController* Controller);
    int BallCrossTheBorder(UBall* Ball);
};

#endif // GAME_H
