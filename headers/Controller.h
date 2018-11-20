#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Mesh.h"
#include "ErrorHandling.h"
#include <string>
#include <iostream>


#define OPENGL_WINDOW_LEFT_X_EDGE -1.0f
#define OPENGL_WINDOW_RIGHT_X_EDGE 1.0f

class UController: public UMesh
{
public:
    UController();
    UController(float X, float Y, float Z, float Width, float Height, UDisplay* Display);
    ~UController();
    void SetVertices();
    void SetPosition(glm::vec3 Position);
    void Update();
    
private:
    float Width;
    float Height;
    int MoveLeftKey;
    int MoveRightKey;
    float MoveSpeed;
    UDisplay* Display;
};

#endif // CONTROLLER_H
