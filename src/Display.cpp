#include "Display.h"

UDisplay::UDisplay()
{
    std::cerr << "Window was created in unproper way!" << std::endl;
    return;
}


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
    
    GLenum GL_Error;
    while ((GL_Error = glGetError()) != GL_NO_ERROR)
    {
        std::cout << glGetError() << std::endl;
    }
    
    std::string SDL_Error = SDL_GetError();
    if (SDL_Error != "")
    {
        std::cerr << "SDL Error: " << SDL_Error << std::endl;
        IsWindowClosed = true;  
    }
    else
    {
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
    }
    
    this->WindowWidth = Width;
    this->WindowHeight = Height;
    
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
    //while (SDL_PollEvent(&Event)) 
    SDL_PollEvent(&Event);
    //{
    
    if (Event.type == SDL_QUIT)
    {
        IsWindowClosed = true;
    }
    else
    {
        const Uint8* KeyStates = SDL_GetKeyboardState(NULL);
        if (Event.type == SDL_KEYDOWN && Event.key.repeat == 0)
        {
            this->UnhandledKeyPress = Event.key.keysym.scancode;
            this->KeyStatus = 1;
        }
        if (Event.type == SDL_KEYUP && !KeyStates[SDL_SCANCODE_A] && !KeyStates[SDL_SCANCODE_D])
        {
            this->UnhandledKeyPress = EMPTY_KEY_SYMBOL;
            this->KeyStatus = 0;
        }
    }
    //}
    
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


void UDisplay::KeyPressBeenHandled()
{
    UnhandledKeyPress = EMPTY_KEY_SYMBOL;
}


int UDisplay::IsKeyPushed()
{
    return KeyStatus;
}


float UDisplay::GetPixelWidth() const { return PixelWidth; }
float UDisplay::GetPixelHeight() const { return PixelHeight; }
int UDisplay::GetUnhandledKeyPress() const { return UnhandledKeyPress; }
int UDisplay::GetWindowWidth() const { return WindowWidth; }
int UDisplay::GetWindowHeight() const { return WindowHeight; }


