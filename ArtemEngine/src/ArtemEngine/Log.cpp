#include "aepch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace ArtemEngine
{
	
	std::shared_ptr<spdlog::logger> Log::sCoreLogger_;
	std::shared_ptr<spdlog::logger> Log::sClientLogger_;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%n]: %v%$");

		sCoreLogger_ = spdlog::stdout_color_mt("ENGINE");
		sCoreLogger_->set_level(spdlog::level::trace);

		sClientLogger_ = spdlog::stdout_color_mt("ARTEM");
		sClientLogger_->set_level(spdlog::level::trace);

		AR_CORE_INFO("Initialized Log");
	}

}