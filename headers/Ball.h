#ifndef BALL_H
#define BALL_H

#include "Mesh.h"

class UBall: public UMesh
{
public:
    UBall(float X, float Y, float Z, float Radius, UDisplay* Display);
    ~UBall();
    void SetVertices();
    glm::vec3 GetMiddlePoint();
    float GetSpeed() const;
    glm::vec3 GetDirection() const;
    
private:
    float Radius;
    float Speed;
    glm::vec3 Direction;
};

#endif // BALL_H
