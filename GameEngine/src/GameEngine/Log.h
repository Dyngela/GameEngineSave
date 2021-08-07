#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace NE {

	  class NE_API Log
	  {
	  public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	  private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	  };

}

// core log macro
#define NE_CORE_TRACE(...)   ::NE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NE_CORE_INFO(...)    ::NE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NE_CORE_WARN(...)    ::NE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NE_CORE_ERROR(...)   ::NE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NE_CORE_FATAL(...)   ::NE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macro
#define NE_TRACE(...)   ::NE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NE_INFO(...)    ::NE::Log::GetClientLogger()->info(__VA_ARGS__)
#define NE_WARN(...)    ::NE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NE_ERROR(...)   ::NE::Log::GetClientLogger()->error(__VA_ARGS__)
#define NE_FATAL(...)   ::NE::Log::GetClientLogger()->fatal(__VA_ARGS__)


