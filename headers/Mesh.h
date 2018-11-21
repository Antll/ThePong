#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "Display.h"
#include "ErrorHandling.h"

#define OUT

class UVertex
{
public:
    UVertex();
    UVertex(glm::vec3 Position);
    glm::vec3 GetPosition();
    void SetPosition(glm::vec3 NewPosition);
    
private:
    glm::vec3 Position;
};


class UMesh
{
public:
    virtual ~UMesh();
    void ConvertCoordinates(float& X, float& Y, float& Z, float& Width, float& Height, const UDisplay* Display);
    void ConvertCoordinates(float& X, float& Y, float& Z, float& Radius, const UDisplay* Display);
    void GenerateBuffers();
    void Delete();
    void Draw();
    glm::vec3 GetMiddlePoint();
    void Move(glm::vec3 NewPosition);
    virtual void SetVertices() = 0;
    
protected:
    glm::vec3 Position;
    GLuint VertexArrayObject;
    GLuint VertexArrayBuffer;
    int VerticesCount;
    UVertex* VertexBufferData;
    UDisplay* Display;
};

#endif // MESH_H
