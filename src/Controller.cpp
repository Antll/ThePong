#include "Controller.h"


UController::UController(float X, float Y, float Z, float Width, float Height, UDisplay* Display)
{
    ConvertCoordinates(X,  Y,  Z, Width, Height, Display);
    VerticesCount = 3;
    VertexBufferData = new UVertex[VerticesCount];
    SetVertices();
    SetPosition(this->Position);
    BindBuffers(VertexBufferData);
    return;
}


UController::~UController()
{
    Delete();
    return;
}


void UController::SetVertices()
{
    UVertex Vertex1(glm::vec3(-1.0f, -1.0f, 0.0f));  // Left
    UVertex Vertex2(glm::vec3(-1.0f + Width, -1.0f, 0.0f)); // Right
    UVertex Vertex3(glm::vec3(-1.0f + Width / 2.0f, -1.0f + Height, 0.0f)); // Top
    
    VertexBufferData[0] = Vertex1;
    VertexBufferData[1] = Vertex2;
    VertexBufferData[2] = Vertex3;
    
    return;
}


void UController::SetPosition(glm::vec3 Position)
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
    
    this->Position = glm::vec3(SumX / 3.0f, SumY / 3.0f, SumZ / 3.0f);
    float DifferenceX = Position.x - this->Position.x;
    float DifferenceY = Position.y - this->Position.y;
    float DifferenceZ = Position.z - this->Position.z;
    
    // Move until point equal to defined position
    for (int i = 0; i < VerticesCount; i++)
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
