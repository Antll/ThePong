#ifndef DEBUG_LINE_H
#define DEBUG_LINE_H

#include "Mesh.h"

class UDebugLine : public UMesh
{
public:
    UDebugLine(glm::vec3 X, glm::vec3 Y);
    ~UDebugLine();
    void SetVertices();
    void SetVertices(glm::vec3 X, glm::vec3 Y);
};

#endif // DEBUG_LINE_H
