#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

#include "Controller.h"
#include "Ball.h"

class UAIController : public UController
{
public:
    UAIController(float X, float Y, float Z, float Width, float Height, UDisplay* Display);
    ~UAIController();
    void Update();
    void SetBallPosition(const UBall& Ball);
    
private:
    glm::vec3 BallPosition;
};

#endif // AI_CONTROLLER_H
