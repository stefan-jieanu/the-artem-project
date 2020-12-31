#pragma once

#include <Windows.h>

namespace artem {

	class Timer
	{
	private:
		LARGE_INTEGER start_;
		double frequency_;
	public:
		Timer()
		{
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			frequency_ = 1.0 / frequency.QuadPart;
			QueryPerformanceCounter(&start_);
		}

		void Reset()
		{
			QueryPerformanceCounter(&start_);
		}

		float Elapsed()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned _int64 cycles = current.QuadPart - start_.QuadPart;
			return (float)(cycles * frequency_);
		}
	};

}