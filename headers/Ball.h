#ifndef BALL_H
#define BALL_H

#include "Mesh.h"
#include <math.h>

class UBall: public UMesh
{
public:
    UBall(float X, float Y, float Z, float Radius, UDisplay* Display);
    ~UBall();
    void SetVertices();
    void RotateDirection(float Angle);
    
    float GetSpeed() const;
    glm::vec3 GetDirection() const;
    float GetDirectionAngleDeg() const;
    float GetRadius() const;
    int GetLastCollision() const;
    void SetLastCollision(const int ObjectValue);
    
private:
    float Radius;
    float Speed;
    glm::vec3 Direction;
    float DirectionAngle;
    int LastCollision;
    static constexpr float PI = 3.1415926f;
};

#endif // BALL_H
