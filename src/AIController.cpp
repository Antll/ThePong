#include "AIController.h"


UAIController::UAIController(float X, float Y, float Z, float Width, float Height, UDisplay* Display)
{
    ConvertCoordinates(X,  Y,  Z, Width, Height, Display);
    this->Width = Width;
    this->Height = Height;
    VerticesCount = 6;
    VertexBufferData = new UVertex[VerticesCount];
    SetVertices();
    this->Position = GetMiddlePoint();
    Move(glm::vec3(X, Y, Z));
    GenerateBuffers();
    this->Display = Display;
    MoveSpeed = 0.01f;
    
    return;
}


UAIController::~UAIController()
{
    return;
}


void UAIController::Update()
{
    if ((this->BallPosition.x - this->GetMiddlePoint().x > 0) 
        && (this->GetMiddlePoint().x + this->Width / 2.0 < OPENGL_WINDOW_RIGHT_X_EDGE))
    {
        Move(glm::vec3(this->Position.x + MoveSpeed, this->Position.y, this->Position.z));
    }
    
    if ((this->BallPosition.x - this->GetMiddlePoint().x < 0)
        && (this->GetMiddlePoint().x - this->Width / 2.0 > OPENGL_WINDOW_LEFT_X_EDGE))
    {
        Move(glm::vec3(this->Position.x - MoveSpeed, this->Position.y, this->Position.z));
    }
    
    return;
}


void UAIController::PutBallPosition(const UBall* Ball)
{
    this->BallPosition = Ball->GetMiddlePoint();
}
