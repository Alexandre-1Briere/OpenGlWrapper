#include "shader.h"
unsigned int shader::createShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    //this function create the shader program do not alter it
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

unsigned int shader::readFullShaderFile(const std::string& fileName)
{
    std::string shader[2];
    return shader::createShader(shader[0], shader[1]);
}

unsigned int shader::CompileShader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    std::string sourceString = source;
    const char* src = sourceString.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* msg = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, msg);
        LogMessage::error("Failed to compile shader : ");
        LogMessage::error(msg);
        return 0;
    }
    return id;
}