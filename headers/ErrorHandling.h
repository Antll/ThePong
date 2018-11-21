#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <GL/glew.h>
#include <iostream>
#include <signal.h>

#ifdef SIGTRAP 
    #define BREAK_POINT raise(SIGTRAP);
#else 
    #define BREAK_POINT raise(SIGABRT);
#endif

#define ASSERT(x) if (!(x)) BREAK_POINT
#define GL_CHECK(x) GLClearError(); \
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))
    
#define LOG(x) std::cout << x << std::endl;

void GLClearError();
bool GLLogCall(const char* FunctionName, const char* SourceFileName, int Line);

#endif // ERROR_HANDLING_H
