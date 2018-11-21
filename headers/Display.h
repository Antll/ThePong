/*
 * Creates an OpenGL window
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <iostream>
#include "ErrorHandling.h"

#define EMPTY_KEY_SYMBOL 0

class UDisplay
{
public:
    UDisplay();
    UDisplay(int Width, int Height, const char* Title);
    ~UDisplay();
    void Update();
    bool IsClosed();
    void ClearColor(float Red, float Green, float Blue, float Alpha);
    void KeyPressBeenHandled();
    int IsKeyPushed();
    float GetPixelWidth() const;
    float GetPixelHeight() const;
    int GetUnhandledKeyPress() const;
    int GetWindowWidth() const;
    int GetWindowHeight() const;
    
private:
    SDL_Window *Window;
    SDL_GLContext GLContext;
    SDL_Event Event;
    Uint8 KeyStatus;
    bool IsWindowClosed;
    int WindowHeight;
    int WindowWidth;
    float PixelHeight;
    float PixelWidth;
    int UnhandledKeyPress;
};

#endif // DISPLAY_H
