#pragma once
#ifndef PARAMETER
#define PARAMETER

enum ErrorLevel
{
	CRITICAL = 0,
	ERROR = 1,
	WARNING = 2,
	INFOS = 3
};

#define ERROR_LEVEL ErrorLevel::INFOS
#define WINDOW_NAME "project name"
#define WINDOW_HEIGHT 480
#define WINDOW_WIDTH 1000

#endif // !PARAMETER