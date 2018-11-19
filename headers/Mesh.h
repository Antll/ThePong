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
    void ConvertCoordinates(float& X, float& Y, float& Z, float& Width, float& Height, const UDisplay* Display);
    void GenerateBuffers();
    void Delete();
    void Draw();
    glm::vec3 GetMiddlePoint();
    virtual void SetVertices() = 0;
    virtual void SetPosition(glm::vec3 Position) = 0;
    
protected:
    glm::vec3 Position;
    float Width;
    float Height;
    GLuint VertexArrayObject;
    GLuint VertexArrayBuffer;
    int VerticesCount;
    UVertex* VertexBufferData;
};

#endif // MESH_H
