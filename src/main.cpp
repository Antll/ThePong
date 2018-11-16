#include "Display.h"
#include "Shader.h"
#include "Controller.h"

int main()
{
    UDisplay Display(800, 600, "The Pong");
    UShader Shader("./src/shaders/VertexShader.glsl", "./src/shaders/FragmentShader.glsl");
    UController Player(0.0f, -280.0f, 0.0f, 90.0f, 20.0f, &Display);
    
    while (!Display.IsClosed())
    {
        Display.ClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        Player.Draw();
        Shader.UseProgram();
        Display.Update();
    }
    
    return 0;
}
