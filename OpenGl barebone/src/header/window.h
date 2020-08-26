#pragma once
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "log.h"
#include "shader.h"
#include "Parameter.h"
#include "variable.h"

class window
{
private:
	dataStruct* data;
	shader compilator;
public:
	window();
	void start();
	void update();
	bool end();
};

