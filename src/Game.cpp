#include "Game.h"

UGame::UGame(UDisplay* Display)
{
    Player = new UController(0.0f, -280.0f, 0.0f, 100.0f, 20.0f, Display);
    TwinPlayer = new UController(0.0f, 280.0f, 0.0f, 100.0f, 20.0f, Display);
    Ball = new UBall(0.0f, 0.0f, 0.0f, 30.0f, Display);
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
    Player->Update();
    TwinPlayer->Update();
    Player->Draw();
    TwinPlayer->Draw();
    return;
}
