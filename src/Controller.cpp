#include "Controller.h"


UController::UController()
{
    this->Width = 0.0f;
    this->Height = 0.0f;
    this->VerticesCount = 0;
    this->Position = glm::vec3(0.0f, 0.0f, 0.0f);
    VertexBufferData = nullptr;
}


UController::UController(float X, float Y, float Z, float Width, float Height, UDisplay* Display)
{
    ConvertCoordinates(X,  Y,  Z, Width, Height, Display);
    this->Width = Width;
    this->Height = Height;
    VerticesCount = 6;
    VertexBufferData = new UVertex[VerticesCount];
    SetVertices();
    this->Position = GetMiddlePoint();
    SetPosition(glm::vec3(X, Y, Z));
    GenerateBuffers();
    this->Display = Display;
    MoveSpeed = 0.01f;
    
    // Also watch in UDisplay Update function if you want to change
    // the keys values
    MoveLeftKey = SDL_SCANCODE_A;   
    MoveRightKey = SDL_SCANCODE_D;
    return;
}


UController::~UController()
{
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


void UController::Update()
{
    int PressedKeyName = Display->GetUnhandledKeyPress();
    if (PressedKeyName != EMPTY_KEY_SYMBOL)
    {
        if(PressedKeyName == MoveLeftKey && 
            ((GetMiddlePoint().x - this->Width / 2.0f - MoveSpeed) >= OPENGL_WINDOW_LEFT_X_EDGE)
        )
        {
                SetPosition(glm::vec3(this->Position.x - MoveSpeed, this->Position.y, this->Position.z));
        }
        
        if(PressedKeyName == MoveRightKey &&
            ((GetMiddlePoint().x + this->Width / 2.0f + MoveSpeed) <= OPENGL_WINDOW_RIGHT_X_EDGE)
        )
        {
            SetPosition(glm::vec3(this->Position.x + MoveSpeed, this->Position.y, this->Position.z));
        }
    }
    
    return;
}

