#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include "Core.h"

namespace Engine {
	class ENGINE_API Log {
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();
		static void Test();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};
}

//---------------------------------------------
//calling macro to make the call cleaner/easier
//---------------------------------------------

#ifdef DEBUG
#define NG_CORE_TRACE(...)     Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NG_CORE_INFOS(...)     Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NG_CORE_WARNING(...)   Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NG_CORE_ERROR(...)     Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NG_CORE_CRITICAL(...)  Engine::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define NG_TRACE(...)     Engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NG_INFOS(...)     Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define NG_WARNING(...)   Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NG_ERROR(...)     Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define NG_CRITICAL(...)  Engine::Log::GetClientLogger()->critical(__VA_ARGS__)
#endif // DEBUG
