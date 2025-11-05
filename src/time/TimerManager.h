#pragma once
#include "utils/Singleton.h"
#include "Timer.h"

namespace engine
{
	class TimerManager : public Singleton<TimerManager>
	{
		friend Timer;

		// An object that contains all the time data.
		sf::Clock clock;
		// Time since the start of the program
		float time;
		// Temporarily stores the previous frame duration.
		float lastTime;
		// Update the FPS counter
		float lastFrameTime;
		// Time since the last image was rendered
		float elapsedTime;
		// Time since the last image was rendered with the 'timeScale'
		float deltaTime;
		// The speed at which time passes
		float timeScale;
		// Number of images that have been rendered since the beginning of the program.
		long long int framesCount;
		// Maximum number of images to render per second
		unsigned short maxFrameRate;
		std::set<Timer*> allTimers;

	private:
		FORCEINLINE float GetTime(const sf::Time& _time) const
		{
			return _time.asSeconds();
		}
		FORCEINLINE std::string ComputeTime(const int _value) const
		{
			if (_value >= 10) return std::to_string(_value);
			return "0" + std::to_string(_value);
		}
	public:
		FORCEINLINE std::string GetCurrentRealTime() const
		{
			const time_t& _now = std::time(0);

			tm _ltm;
			localtime_s(&_ltm, &_now);

			const std::string& _date = ComputeTime(_ltm.tm_mday) + "/" + ComputeTime(1 + _ltm.tm_mon) + "/" + ComputeTime(1900 + _ltm.tm_year);
			const std::string& _time = ComputeTime(_ltm.tm_hour) + ":" + ComputeTime(_ltm.tm_min) + ":" + ComputeTime(_ltm.tm_sec);

			return _date + " " + _time;
		}
		FORCEINLINE void AddTimer(Timer* _timer)
		{
			allTimers.insert(_timer);
		}
		FORCEINLINE void RemoveTimer(Timer* _timer)
		{
			if (!allTimers.contains(_timer)) return;

			_timer->Stop();
			allTimers.erase(_timer);
			delete _timer;
		}
		FORCEINLINE void SetTimerScale(const float& _timeScale)
		{
			timeScale = _timeScale;
		}
		FORCEINLINE float ComputeFPS() const
		{
			return 1.0f / (time - lastFrameTime); // 1.0f is for seconds (replace it by 1000.0f for milliseconds)
		}
		FORCEINLINE sf::Time GetDeltaTime() const
		{
			return sf::Time(sf::seconds(CAST(float, deltaTime * 1.0f))); // 1.0f is for seconds (replace it by 1000.0f for milliseconds)
		}

	public:
		TimerManager();
		~TimerManager();

		float Update();
		void Pause();
		void Resume();
		void Stop();
	};
}