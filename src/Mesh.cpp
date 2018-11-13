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


UMesh::UMesh(float X, float Y, float Z, float Width, float Height, UDisplay* Display)
{
    float PixelHeight = Display->GetPixelHeight();
    float PixelWidth = Display->GetPixelWidth();
    
    this->Position = glm::vec3(X * PixelWidth, Y * PixelHeight, Z);
    this->Width = Width * PixelWidth;
    this->Height = Height * PixelHeight;
    SetVertices();
    SetPosition(this->Position);
    
    glGenVertexArrays(1, OUT &VertexArrayObject);
    glBindVertexArray(VertexArrayObject);
    
    glGenBuffers(1, &VertexArrayBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, VertexArrayBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexBufferData), VertexBufferData, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(0);
    return;
}


UMesh::~UMesh()
{
    glDeleteVertexArrays(1, OUT &VertexArrayObject);
    return;
}


void UMesh::Draw()
{
    glBindVertexArray(VertexArrayObject);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VertexArrayBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glDrawArrays(GL_TRIANGLES, 0, VERTICES_COUNT);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
    return;
}


void UMesh::SetVertices()
{
    UVertex Vertex1(glm::vec3(-1.0f, -1.0f, 0.0f));  // Left
    UVertex Vertex2(glm::vec3(-1.0f + Width, -1.0f, 0.0f)); // Right
    UVertex Vertex3(glm::vec3(-1.0f + Width / 2.0f, -1.0f + Height, 0.0f)); // Top
    
    VertexBufferData[0] = Vertex1;
    VertexBufferData[1] = Vertex2;
    VertexBufferData[2] = Vertex3;
    
    return;
}


void UMesh::SetPosition(glm::vec3 Position)
{
    // Find the the middle point
    float SumX = 0.0f;
    float SumY = 0.0f;
    float SumZ = 0.0f;
    for (int i = 0; i < VERTICES_COUNT; i++)
    {
        SumX += VertexBufferData[i].GetPosition().x;
        SumY += VertexBufferData[i].GetPosition().y;
        SumZ += VertexBufferData[i].GetPosition().z;
    }
    
    this->Position = glm::vec3(SumX / 3.0f, SumY / 3.0f, SumZ / 3.0f);
    float DifferenceX = Position.x - this->Position.x;
    float DifferenceY = Position.y - this->Position.y;
    float DifferenceZ = Position.z - this->Position.z;
    
    // Move until point equal to defined position
    for (int i = 0; i < VERTICES_COUNT; i++)
    {
        glm::vec3 MoveVector = glm::vec3(
                                    VertexBufferData[i].GetPosition().x + DifferenceX,
                                    VertexBufferData[i].GetPosition().y + DifferenceY,
                                    VertexBufferData[i].GetPosition().z + DifferenceZ 
                                    );
        
        VertexBufferData[i] = MoveVector;
    }
    
    return;
}
