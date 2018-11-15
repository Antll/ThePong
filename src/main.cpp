#include "Display.h"
#include "Shader.h"
#include "Controller.h"

int main()
{
    UDisplay Display(800, 600, "The Pong");
    UShader Shader("./src/shaders/VertexShader.glsl", "./src/shaders/FragmentShader.glsl");
    UController Player(100, 100, 0, 100, 100, &Display);
    UController SecondPlayer(-100, -100, 0, 100, 100, &Display);
    
    while (!Display.IsClosed())
    {
        Display.ClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        Player.Draw();
        SecondPlayer.Draw();
        Shader.UseProgram();
        Display.Update();
    }
    
    return 0;
}
