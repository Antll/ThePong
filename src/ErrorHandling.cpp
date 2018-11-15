#include "ErrorHandling.h"


void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
    return;
}


bool GLLogCall(const char* FunctionName, const char* SourceFileName, int Line)
{
    while (GLenum Error = glGetError())
    {
        std::cout << "[OpenGL Error]: " << std::hex << Error << ": "
            << FunctionName << "() in " << SourceFileName << ":" << Line << std::endl;
        return false;
    }
    
    return true;
}
