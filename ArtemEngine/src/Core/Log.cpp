#include "Log.hpp"

namespace Engine
{
    
std::shared_ptr<spdlog::logger> Log::coreLogger_;
std::shared_ptr<spdlog::logger> Log::clientLogger_;

void Log::Init()
	{
		spdlog::set_pattern("%^[%n]: [%s, %#]: [%l]: %v%$");

		coreLogger_ = spdlog::stdout_color_mt("ENGINE");
		coreLogger_->set_level(spdlog::level::trace);

		clientLogger_ = spdlog::stdout_color_mt("CLIENT");
		clientLogger_->set_level(spdlog::level::trace);

		LOG_CORE_INFO("Initialized Log");
	}

} // namespace Engine
