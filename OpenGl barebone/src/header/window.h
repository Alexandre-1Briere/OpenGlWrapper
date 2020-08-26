#pragma once
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "shader.h"

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

