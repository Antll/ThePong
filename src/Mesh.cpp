#include "Mesh.h"

UVertex::UVertex()
{
    this->Position = glm::vec3(0.0f, 0.0f, 0.0f);
}


UVertex::UVertex(glm::vec3 Position)
{
    this->Position = Position;
    return;
}


glm::vec3 UVertex::GetPosition()
{
    return Position;
}


void UVertex::SetPosition(glm::vec3 NewPosition)
{
    this->Position = NewPosition;
    return;
}


void UMesh::Draw()
{
    glBindVertexArray(VertexArrayObject);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, VerticesCount);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
    return;
}


void UMesh::BindBuffers(UVertex* VertexBufferData)
{
    glGenVertexArrays(1, OUT &VertexArrayObject);
    glBindVertexArray(VertexArrayObject);
    
    glGenBuffers(1, &VertexArrayBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, VertexArrayBuffer);
    glBufferData(GL_ARRAY_BUFFER, VerticesCount * sizeof(VertexBufferData[0]), VertexBufferData, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    
    glBindVertexArray(0);
    return;
}


void UMesh::Delete()
{
    glDeleteVertexArrays(1, OUT &VertexArrayObject);
    return;
}


void UMesh::ConvertCoordinates(float X, float Y, float Z, float Width, float Height, UDisplay* Display)
{
    float PixelHeight = Display->GetPixelHeight();
    float PixelWidth = Display->GetPixelWidth();
    
    this->Position = glm::vec3(X * PixelWidth, Y * PixelHeight, Z);
    this->Width = Width * PixelWidth;
    this->Height = Height * PixelHeight;
    return;
}
