#pragma once
#ifndef LOGMESSAGE
#define LOGMESSAGE

#include <string>
#include <iostream>
#include "Parameter.h"

class LogMessage
{
public:
	static const ErrorLevel LogLevel = ERROR_LEVEL;

	static void critical(const std::string& message) {
		if (LogLevel >= CRITICAL) {
			std::cout << "\033[1m\033[31m" << message << "\033[0m" << std::endl;
		}
	};
	static void error(const std::string& message){
		if (LogLevel >= ERROR) {
			std::cout << "\033[31m" << message << "\033[0m" << std::endl;
		}
	};
	static void warning(const std::string& message) {
		if (LogLevel >= WARNING) {
			std::cout << "\033[33m" << message << "\033[0m" << std::endl;
		}
	};
	static void infos(const std::string& message) {
		if (LogLevel >= INFOS) {
			std::cout << "\033[37m" << message << "\033[0m" << std::endl;
		}
	};
};


#endif // !LOGMESSAGE