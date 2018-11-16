#include "Controller.h"


UController::UController(float X, float Y, float Z, float Width, float Height, const UDisplay* Display)
{
    ConvertCoordinates(X,  Y,  Z, Width, Height, Display);
    this->Width = Width;
    this->Height = Height;
    VerticesCount = 6;
    VertexBufferData = new UVertex[VerticesCount];
    SetVertices();
    this->Position = GetMiddlePoint();
    SetPosition(glm::vec3(X, Y, Z));
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
    UVertex Vertex1(glm::vec3(-1.0f, -1.0f, 0.0f));  // Bottom Left
    UVertex Vertex2(glm::vec3(-1.0f + Width, -1.0f, 0.0f)); // Bottom Right
    UVertex Vertex3(glm::vec3(-1.0f, -1.0f + Height, 0.0f)); // Top Left
    
    UVertex Vertex4(glm::vec3(-1.0f, -1.0f + Height, 0.0f)); // Top Left
    UVertex Vertex5(glm::vec3(-1.0f + Width, -1.0f + Height, 0.0f)); // Top Right
    UVertex Vertex6(glm::vec3(-1.0f + Width, -1.0f, 0.0f)); // Bottom Right
    
    VertexBufferData[0] = Vertex1;
    VertexBufferData[1] = Vertex2;
    VertexBufferData[2] = Vertex3;
    
    VertexBufferData[3] = Vertex4;
    VertexBufferData[4] = Vertex5;
    VertexBufferData[5] = Vertex6;
    
    return;
}


void UController::SetPosition(glm::vec3 NewPosition)
{
    float DifferenceX = NewPosition.x - this->Position.x;
    float DifferenceY = NewPosition.y - this->Position.y;
    float DifferenceZ = NewPosition.z - this->Position.z;
    
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
