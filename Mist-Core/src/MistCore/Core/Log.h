#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace MistCore {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};

}

#define LOG_TRACE(...)         ::MistCore::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)          ::MistCore::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)          ::MistCore::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)         ::MistCore::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)      ::MistCore::Log::GetLogger()->critical(__VA_ARGS__)
