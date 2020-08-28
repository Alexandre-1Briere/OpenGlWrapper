#include "Log.h"
#pragma once

namespace Engine {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("Engine");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("Application");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
	void Log::Test()
	{
		printf("ENGINE LOGGER");
		NG_CORE_TRACE("trace testing");
		NG_CORE_INFOS("infos testing");
		NG_CORE_WARNING("warning testing");
		NG_CORE_ERROR("error testing");
		NG_CORE_CRITICAL("critical testing");
		printf("CLIENT LOGGER");
		NG_TRACE("trace testing");
		NG_INFOS("infos testing");
		NG_WARNING("warning testing");
		NG_ERROR("error testing");
		NG_CRITICAL("critical testing");
	}
}