#include "Shader.h"

UShader::UShader(const char* VertexShaderFilePath, const char* FragmentShaderFilePath)
{
    VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(VertexShaderFilePath, std::ios::in);
    if (VertexShaderStream.is_open())
    {
        std::stringstream SStream;
        SStream << VertexShaderStream.rdbuf();
        VertexShaderCode = SStream.str();
        VertexShaderStream.close();
    }
    else 
    {
        std::cout << "Can't find " << VertexShaderFilePath << " file" << std::endl;
        ProgramID = 0;
    }
    
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(FragmentShaderFilePath, std::ios::in);
    if (FragmentShaderStream.is_open())
    {
        std::stringstream SStream;
        SStream << FragmentShaderStream.rdbuf();
        FragmentShaderCode = SStream.str();
        FragmentShaderStream.close();
    }
    else 
    {
        std::cout << "Can't find " << FragmentShaderFilePath << " file" << std::endl;
        ProgramID = 0;
    }
    
    GLint Result = GL_FALSE;
    int InfoLogLength;
    
    // Compile vertex shader
    std::cout << "Compiling shader: " << VertexShaderFilePath << std::endl;
    char const* VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
    glCompileShader(VertexShaderID);
    
    // Check vertex shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0)
    {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        std::cout << &VertexShaderErrorMessage[0] << std::endl;
    }
    
    // Compile fragment shader
    std::cout << "Compiling shader : " << FragmentShaderFilePath << std::endl;
    char const* FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
    glCompileShader(FragmentShaderID);
    
    // Check fragment shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0)
    {
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        std::cout << &FragmentShaderErrorMessage[0] << std::endl;
    }
    
    // Link the program
    std::cout << "Linking program" << std::endl;
    ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);
    
    // Check the program
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0)
    {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        std::cout << &ProgramErrorMessage[0] << std::endl;
    }
    
    glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);
    
    return;
}


void UShader::UseProgram()
{
    glUseProgram(ProgramID);
}
