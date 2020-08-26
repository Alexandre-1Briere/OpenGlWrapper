#pragma once
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "log.h"
#include "Parameter.h"
#include "variable.h"
class shader
{
public:
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int readFullShaderFile(const std::string& fileName);
private:
	unsigned int CompileShader(unsigned int type, const std::string& source);
};

