#include "Display.h"
#include "Shader.h"
#include "Game.h"


int main()
{
    UDisplay Display(800, 600, "The Pong");
    UShader Shader("./src/shaders/VertexShader.glsl", "./src/shaders/FragmentShader.glsl");
    UGame Game(&Display);
    
    while (!Display.IsClosed())
    {
        Display.ClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        Shader.UseProgram();
        Game.Update();
        Display.Update();
    }
    
    return 0;
}
