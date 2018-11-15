#include "Display.h"

UDisplay::UDisplay(int Width, int Height, const char* Title)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    Window = SDL_CreateWindow(Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_OPENGL);
    GLContext = SDL_GL_CreateContext(Window);
    IsWindowClosed = false;
    PixelWidth = 2.0f / Width;
    PixelHeight = 2.0f / Height;
    
    GLenum Status = glewInit();
    if (Status == GLEW_OK)
    {
        std::cout << "Window was been created with " << Width << "x" << Height << " resolution\n";
    }
    else
    {
        std::cerr << "Glew failed to initialze!\n";
    }
    
    return;
}


UDisplay::~UDisplay()
{
    SDL_GL_DeleteContext(GLContext);
    SDL_DestroyWindow(Window);
    SDL_Quit();
    std::cout << "Window was been destroyed\n";
    return;
}


void UDisplay::Update()
{
    SDL_GL_SwapWindow(Window);
    
    SDL_Event Event;
    while (SDL_PollEvent(&Event))
    {
        if (Event.type == SDL_QUIT)
        {
            IsWindowClosed = true;
        }
    }
    
    return;
}


bool UDisplay::IsClosed()
{
    return IsWindowClosed;
}


void UDisplay::ClearColor(float Red, float Green, float Blue, float Alpha)
{
    glClearColor(Red, Green, Blue, Alpha);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    return;
}


float UDisplay::GetPixelWidth() const { return PixelWidth; }
float UDisplay::GetPixelHeight() const { return PixelHeight; }

