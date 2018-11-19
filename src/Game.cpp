#include "Game.h"

UGame::UGame(UDisplay* Display)
{
    Player = new UController(0.0f, -280.0f, 0.0f, 100.0f, 20.0f, Display);
    return;
}


UGame::~UGame()
{
    Player = nullptr;
    return;
}


void UGame::Update()
{
    Player->Update();
    Player->Draw();
    return;
}
