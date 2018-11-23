#include "Game.h"

UGame::UGame(UDisplay* Display)
{
    Player = new UController(0.0f, -280.0f, 0.0f, 100.0f, 20.0f, Display);
    TwinPlayer = new UController(0.0f, 280.0f, 0.0f, 100.0f, 20.0f, Display);
    Ball = new UBall(0.0f, 0.0f, 0.0f, 10.0f, Display); // 10 - default radious
    return;
}


UGame::~UGame()
{
    delete Player;
    delete TwinPlayer;
    delete Ball;
    return;
}


void UGame::Update()
{
    Ball->Move(Ball->GetDirection());
 
    srand(time(NULL));
    float Angle = 90.0f + (-10.f + rand() % 21);
    if (IsBallOverlapedWithController(Ball, TwinPlayer)
        && Ball->GetLastCollision() != TWIN_PLAYER
    )
    {
        Ball->RotateDirection(Angle);
        Ball->SetLastCollision(TWIN_PLAYER);
    }
    
    if (IsBallOverlapedWithController(Ball, Player)
        && Ball->GetLastCollision() != PLAYER
    )
    {
        Ball->RotateDirection(Angle);
        Ball->SetLastCollision(PLAYER);
    }
    
    if (IsBallGetOverTheScreen(Ball)
        && Ball->GetLastCollision() != WALL
    )
    {
        Ball->RotateDirection(90);
        Ball->SetLastCollision(WALL);
    }
    
    Player->Update();
    TwinPlayer->Update();
    Player->Draw();
    TwinPlayer->Draw();
    Ball->Draw();
    return;
}


bool UGame::IsBallOverlapedWithController(UBall* Ball, UController* Controller)
{
    static const float MAX_CONTROLLER_RADIUS = sqrt(
        Controller->GetWidth() * Controller->GetWidth() / 4.0f +
        Controller->GetHeight() * Controller->GetHeight() / 4.0f
    );
    
    bool IsOverlaping = false;
    float AlphaX = abs(Ball->GetMiddlePoint().x - Controller->GetMiddlePoint().x);
    float AlphaY = abs(Ball->GetMiddlePoint().y - Controller->GetMiddlePoint().y);
    float Distance = sqrt(AlphaX * AlphaX + AlphaY * AlphaY);
    float ControllerRadius = Controller->GetHeight() / 2.0f * Distance / AlphaY;
    
    
    if (ControllerRadius < MAX_CONTROLLER_RADIUS
        && Distance < Ball->GetRadius() + ControllerRadius)
    {
        IsOverlaping = true;
    }
    
    return IsOverlaping;
}


bool UGame::IsBallGetOverTheScreen(UBall* Ball)
{
    bool IsOver = false;
    
    if ((Ball->GetMiddlePoint().x - Ball->GetRadius() < -1.0f)
        || (Ball->GetMiddlePoint().x + Ball->GetRadius() > 1.0f)
    )
    {
        IsOver = true;
    }
    
    return IsOver;
}
