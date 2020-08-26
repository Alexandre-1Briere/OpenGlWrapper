#pragma once
#ifndef SHADER
#define SHADER

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "log.h"
#include "variable.h"



enum ShaderIndex {
	VERTEX = 0,
	FRAGMENT = 1,
	NONE = -1
};

class shader
{
public:
	unsigned int test;
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	void readShaderFile(const std::string& fileName);
private:
	unsigned int CompileShader(unsigned int type, const std::string& source);
};


#endif // !SHADER