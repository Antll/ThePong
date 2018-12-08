#include "Ball.h"


UBall::UBall(float X, float Y, float Z, float Radius, UDisplay* Display)
{
    ConvertCoordinates(X, Y, Z, Radius, Display);
    this->Position.x = X;
    this->Position.y = Y;
    this->Position.z = Z;
    this->Radius = Radius;
    this->VerticesCount = 48;  // To draw
    this->VertexBufferData = new UVertex[VerticesCount * 2];
    this->Display = Display;
    this->Speed = 0.005f;   // Default speed
    this->Direction = glm::vec3(this->Position.x + Speed, this->Position.y - Speed, 0.0f);
    this->LastCollision = -1;
    
    this->DirectionAngle = atan(this->Direction.y / this->Direction.x);
    
    GenerateBuffers();
    SetVertices();
    return;
}


UBall::~UBall()
{
    return;
}


void UBall::SetVertices()
{
    constexpr float PI = 3.1415926f;
    float Angle;
    float VertexX;
    float VertexY;
    int VerticesToCalculate = this->VerticesCount / 2;
    int TriangleCount = VerticesToCalculate / 3;
    int j = 0;
    float Ratio = (float)Display->GetWindowHeight() / (float)Display->GetWindowWidth();
    
    for (int i = 0; i < VerticesToCalculate - TriangleCount; i++)
    {
        // Calculate
        Angle = 2.0f * PI * float(i) / float(VerticesToCalculate - TriangleCount);
        VertexX = Radius * cos(Angle);
        VertexY = Radius * sin(Angle);
        
        
        
        UVertex RightTriangleVertex = UVertex(
            glm::vec3((VertexX + this->Position.x) * Ratio, VertexY + this->Position.y, 0.0f)
        );
        
        Angle = 2.0f * PI * float(i + 1) / float(VerticesToCalculate - TriangleCount);
        VertexX = Radius * cos(Angle);
        VertexY = Radius * sin(Angle);
        
        UVertex LeftTriangleVertex = UVertex(
            glm::vec3((VertexX + this->Position.x) * Ratio, VertexY + this->Position.y, 0.0f)
        );
        
        
        // Store
        VertexBufferData[j + 1] = LeftTriangleVertex;
        VertexBufferData[j] = RightTriangleVertex;
        
        j+=2;
        if ((j + 1) % 3 == 0) {
            UVertex CenterCircle = UVertex(glm::vec3(this->Position.x, this->Position.y, 0.0f));
            VertexBufferData[j] = CenterCircle;
            j++;
        }
    }
    
    return;
}


void UBall::RotateDirection(float Angle)
{
    Angle = (Angle * PI) / 180; // Convert to radians
    
    float NewDirectionX = cos(Angle) * this->Direction.x - sin(Angle) * this->Direction.y;
    float NewDirectionY = sin(Angle) * this->Direction.x + cos(Angle) * this->Direction.y;
    
    this->Direction = glm::vec3(NewDirectionX, NewDirectionY, 0.0f);
    this->DirectionAngle += Angle;
    
    while (this->DirectionAngle >= 2.0f * PI)
    {
        this->DirectionAngle -= 2.0f * PI;
    }
    
    return;
}


float UBall::GetSpeed() const { return Speed; }
glm::vec3 UBall::GetDirection() const { return Direction; }
float UBall::GetRadius() const { return Radius; }
int UBall::GetLastCollision() const { return LastCollision; }
float UBall::GetDirectionAngleDeg() const { return DirectionAngle * 180.0f / PI;}


void UBall::SetLastCollision(const int ObjectValue) { this->LastCollision = ObjectValue; }


