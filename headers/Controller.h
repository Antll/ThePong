#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Mesh.h"
#include "ErrorHandling.h"

class UController: public UMesh
{
public:
    UController(float X, float Y, float Z, float Width, float Height, UDisplay* Display);
    ~UController();
    void SetVertices();
    void SetPosition(glm::vec3 Position);
};

#endif // CONTROLLER_H
