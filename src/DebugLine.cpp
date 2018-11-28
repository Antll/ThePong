#include "DebugLine.h"

UDebugLine::UDebugLine(glm::vec3 X, glm::vec3 Y)
{
    this->VerticesCount = 2;
    this->VertexBufferData = new UVertex[VerticesCount];
    this->Position = GetMiddlePoint();
    GenerateBuffers();
    SetVertices(X, Y);
    return;
}


UDebugLine::~UDebugLine()
{
    // VertexBufferData frees in UMesh
    return;
}


void UDebugLine::SetVertices()
{
    VertexBufferData[0] = glm::vec3(-1.0f, -1.0f, 0.0f);
    VertexBufferData[1] = glm::vec3(1.0f, 1.0f, 0.0f);
    return;
}


void UDebugLine::SetVertices(glm::vec3 X, glm::vec3 Y)
{
    VertexBufferData[0] = X;
    VertexBufferData[1] = Y;
    return;
}
