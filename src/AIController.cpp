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
    return;
}


void UAIController::SetBallPosition(const UBall& Ball)
{
    this->BallPosition = Ball.GetMiddlePoint();
}
