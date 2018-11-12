/*
 * Creates an OpenGL window
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

class UDisplay
{
public:
    UDisplay(int Width, int Height, const char* Title);
    ~UDisplay();
    void Update();
    bool IsClosed();
    void ClearColor(float Red, float Green, float Blue, float Alpha);
    
private:
    SDL_Window *Window;
    SDL_GLContext GLContext;
    bool IsWindowClosed;
};

#endif // DISPLAY_H
