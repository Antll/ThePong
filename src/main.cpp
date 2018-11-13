#include "Display.h"
#include "Shader.h"

int main()
{
    UDisplay Display(800, 600, "The Pong");
    UShader Shader("./src/shaders/VertexShader.glsl", "./src/shaders/FragmentShader.glsl");
    
    while (!Display.IsClosed())
    {
        Display.ClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        Shader.UseProgram();
        Display.Update();
    }
    
    return 0;
}
