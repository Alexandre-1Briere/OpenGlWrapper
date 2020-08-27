#pragma once
#ifndef LOGMESSAGE
#define LOGMESSAGE

#include <iostream>
#include <string>
#define ERROR_LEVEL ErrorLevel::INFOS

enum class ErrorLevel {
	CRITICAL = 0,
	ERROR = 1,
	WARNING = 2,
	INFOS = 3,
};

class LogMessage
{
public:
	static const ErrorLevel LogLevel = ERROR_LEVEL;

	static void critical(const std::string& message) {
		if (LogLevel >= ErrorLevel::CRITICAL) {
			std::cout << "\033[1m\033[31m" << message << "\033[0m" << std::endl;
		}
	};
	static void error(const std::string& message){
		if (LogLevel >= ErrorLevel::ERROR) {
			std::cout << "\033[31m" << message << "\033[0m" << std::endl;
		}
	};
	static void warning(const std::string& message) {
		if (LogLevel >= ErrorLevel::WARNING) {
			std::cout << "\033[33m" << message << "\033[0m" << std::endl;
		}
	};
	static void infos(const std::string& message) {
		if (LogLevel >= ErrorLevel::INFOS) {
			std::cout << "\033[37m" << message << "\033[0m" << std::endl;
		}
	};
};


#endif // !LOGMESSAGE