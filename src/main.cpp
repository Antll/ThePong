#include "Display.h"

int main()
{
    UDisplay Display(800, 600, "The Pong");
    
    while (!Display.IsClosed())
    {
        Display.ClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        Display.Update();
    }
    
    return 0;
}
