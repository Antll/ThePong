#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

#include "Controller.h"

class UAIController : public UController
{
public:
    UAIController(float X, float Y, float Z, float Width, float Height, UDisplay* Display);
    ~UAIController();
    void Update();
};

#endif // AI_CONTROLLER_H
