#ifndef BALL_H
#define BALL_H

#include "Mesh.h"

class UBall: public UMesh
{
public:
    UBall(float X, float Y, float Z, float Radius, UDisplay* Display);
    ~UBall();
    void SetVertices();
    
private:
    float Radius;
};

#endif // BALL_H