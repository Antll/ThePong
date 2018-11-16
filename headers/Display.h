/*
 * Creates an OpenGL window
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

#define EMPTY_KEY_SYMBOL ""

class UDisplay
{
public:
    UDisplay(int Width, int Height, const char* Title);
    ~UDisplay();
    void Update();
    bool IsClosed();
    void ClearColor(float Red, float Green, float Blue, float Alpha);
    float GetPixelWidth() const;
    float GetPixelHeight() const;
    std::string GetUnhandledKeyPress() const;
    void KeyPressBeenHandled();
    
private:
    SDL_Window *Window;
    SDL_GLContext GLContext;
    bool IsWindowClosed;
    float PixelWidth;
    float PixelHeight;
    std::string UnhandledKeyPress;
};

#endif // DISPLAY_H
