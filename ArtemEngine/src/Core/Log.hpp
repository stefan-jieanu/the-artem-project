#pragma once

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#define SPDLOG_DEBUG_ON
#define SPDLOG_TRACE_ON

#include "Core.hpp"
#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

// Undefine these spdlog defines as they are only necessary as a tweak before including the library
// No need to have them defined to clutter the rest of the program
#undef SPDLOG_ACTIVE_LEVEL
#undef SPDLOG_DEBUG_ON
#undef SPDLOG_TRACE_ON

namespace Engine
{
    
class ENGINE_API Log
{
public:
    static void Init();
    
    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger_; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger_; }
private:
    static std::shared_ptr<spdlog::logger> coreLogger_;
    static std::shared_ptr<spdlog::logger> clientLogger_;
};

} // namespace Engine

// Core log macros
#define LOG_CORE_TRACE(...) SPDLOG_LOGGER_TRACE(::Engine::Log::GetCoreLogger(), __VA_ARGS__)
#define LOG_CORE_DEBUG(...) SPDLOG_LOGGER_DEBUG(::Engine::Log::GetCoreLogger(), __VA_ARGS__)
#define LOG_CORE_INFO(...) SPDLOG_LOGGER_INFO(::Engine::Log::GetCoreLogger(), __VA_ARGS__)
#define LOG_CORE_WARN(...)  SPDLOG_LOGGER_WARN(::Engine::Log::GetCoreLogger(), __VA_ARGS__)
#define LOG_CORE_ERROR(...) SPDLOG_LOGGER_ERROR(::Engine::Log::GetCoreLogger(), __VA_ARGS__)


// Client log macros
#define LOG_TRACE(...) SPDLOG_LOGGER_TRACE(::Engine::Log::GetClientLogger(), __VA_ARGS__)
#define LOG_DEBUG(...) SPDLOG_LOGGER_DEBUG(::Engine::Log::GetClientLogger(), __VA_ARGS__)
#define LOG_INFO(...) SPDLOG_LOGGER_INFO(::Engine::Log::GetClientLogger(), __VA_ARGS__)
#define LOG_WARN(...)  SPDLOG_LOGGER_WARN(::Engine::Log::GetClientLogger(), __VA_ARGS__)
#define LOG_ERROR(...) SPDLOG_LOGGER_ERROR(::Engine::Log::GetClientLogger(), __VA_ARGS__)
