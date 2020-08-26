#include <fstream>
#include <sstream>
#include "..\header\shader.h"
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

ShaderSource shader::readShaderFile(const std::string& fileName)
{
    std::stringstream shader[2];
    std::ifstream reader(fileName);
    std::string line;
    unsigned int defaultMode = ShaderIndex::NONE;
    if (!reader.is_open()) {
        LogMessage::error("shader file " + fileName + "couldn't be loaded");
        return {"",""};
    }
    while (getline(reader, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) {
                defaultMode = ShaderIndex::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos) {
                defaultMode = ShaderIndex::FRAGMENT;
            }
        }
        else if (defaultMode != ShaderIndex::NONE) {
            shader[defaultMode] << line << "\n";
        }
    }
    ShaderSource returnValue;
    returnValue.VertexSource = shader[ShaderIndex::VERTEX].str();
    returnValue.FragmentSource = shader[ShaderIndex::FRAGMENT].str();
    return returnValue;
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