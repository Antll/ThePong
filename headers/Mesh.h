#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "Display.h"

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
    UMesh(float X, float Y, float Z, float Width, float Height, UDisplay* Display);
    ~UMesh();
    void Draw();
    
private:
    glm::vec3 Position;
    float Width;
    float Height;
    GLuint VertexArrayObject;
    GLuint VertexArrayBuffer;
    static const int VERTICES_COUNT = 3;
    UVertex VertexBufferData[VERTICES_COUNT];
    
    void SetVertices();
    void SetPosition(glm::vec3 Position);
};

#endif // MESH_H
