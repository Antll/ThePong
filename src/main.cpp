#include "Display.h"
#include "Shader.h"
#include "Mesh.h"

int main()
{
    UDisplay Display(800, 600, "The Pong");
    UShader Shader("./src/shaders/VertexShader.glsl", "./src/shaders/FragmentShader.glsl");
    UMesh Mesh(0, 0, 0, 100, 100, &Display);
    
    while (!Display.IsClosed())
    {
        Display.ClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        Mesh.Draw();
        Shader.UseProgram();
        Display.Update();
    }
    
    return 0;
}
