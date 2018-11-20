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


UMesh::~UMesh()
{
    Delete();
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
    glBindBuffer(GL_ARRAY_BUFFER, VertexArrayBuffer);
    
    glBufferData(GL_ARRAY_BUFFER, VerticesCount * sizeof(VertexBufferData[0]), VertexBufferData, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    
    glEnableVertexAttribArray(0);
    
    glDrawArrays(GL_TRIANGLES, 0, VerticesCount);
    
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
    return;
}


void UMesh::GenerateBuffers()
{
    glGenVertexArrays(1, OUT &VertexArrayObject);
    glBindVertexArray(VertexArrayObject);
    glGenBuffers(1, &VertexArrayBuffer);
    glBindVertexArray(0);
    return;
}


void UMesh::Delete()
{
    glDeleteVertexArrays(1, OUT &VertexArrayObject);
    return;
}


void UMesh::ConvertCoordinates(float& X, float& Y, float& Z, float& Width, float& Height, const UDisplay* Display)
{
    float PixelHeight = Display->GetPixelHeight();
    float PixelWidth = Display->GetPixelWidth();
    
    X *= PixelWidth;
    Y *= PixelHeight;
    Z = 0;
    
    Width *= PixelWidth;
    Height *= PixelHeight; 
    return;
}


void UMesh::ConvertCoordinates(float& X, float& Y, float& Z, float& Radius, const UDisplay* Display)
{
    float PixelHeight = Display->GetPixelHeight();
    float PixelWidth = Display->GetPixelWidth();
    
    X *= PixelWidth;
    Y *= PixelHeight;
    Z = 0;
    
    Radius *= PixelHeight;
    return;
}


glm::vec3 UMesh::GetMiddlePoint()
{
    // Find the the middle point
    float SumX = 0.0f;
    float SumY = 0.0f;
    float SumZ = 0.0f;
    for (int i = 0; i < VerticesCount; i++)
    {
        SumX += VertexBufferData[i].GetPosition().x;
        SumY += VertexBufferData[i].GetPosition().y;
        SumZ += VertexBufferData[i].GetPosition().z;
    }
    
    return glm::vec3(SumX / VerticesCount, SumY / VerticesCount, SumZ / VerticesCount);
}
