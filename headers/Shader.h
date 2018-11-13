#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class UShader
{
public:
    UShader(const char* VertexShaderFilePath, const char* FragmentShaderFilePath);
    void UseProgram();
    
private:
    GLuint VertexShaderID;
    GLuint FragmentShaderID;
    GLuint ProgramID;
};

#endif // SHADER_H
