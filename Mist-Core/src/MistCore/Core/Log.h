#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Mist {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};

}

#define LOG_TRACE(...)         ::Mist::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)          ::Mist::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)          ::Mist::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)         ::Mist::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)      ::Mist::Log::GetLogger()->critical(__VA_ARGS__)
