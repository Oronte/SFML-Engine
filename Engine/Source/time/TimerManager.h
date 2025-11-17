#pragma once
#include "utils/Singleton.h"

#define M_TIMER engine::TimerManager::GetInstance()

namespace engine
{
	class Timer;

	class TimerManager : public Singleton<TimerManager>
	{
		friend Timer;

	public:
		Event<> onPauseTimer;
		Event<> onResumeTimer;
		Event<> onStopTimer;

	private:
		sf::Clock clock;				// An object that contains all the time data.

		float lastTimeStamp;			// Timestamp of previous frame (seconds)
		float lastFrameDuration;		// Duration of last frame (raw, seconds)
		float deltaTime;				// Scaled frame duration (lastFrameDuration * timeScale)
		float elapsedTime;				// Raw frame duration
		float timeScale;				// Time speed multiplier

		long long framesCount;			// Total number of frames since program start
		unsigned short maxFrameRate;	// Frame rate cap (0 = unlimited)
		float fps;						
		float smoothedFPS;				// Smoothed FPS for stable display

		std::vector<std::unique_ptr<Timer>> allTimers;

	private:
		FORCEINLINE float GetTime(const sf::Time& _time) const
		{
			return _time.asSeconds();
		}
		FORCEINLINE std::string TwoDigitsTime(const int& _value) const
		{
			if (_value >= 10) return std::to_string(_value);
			return "0" + std::to_string(_value);
		}
	
	public:
		FORCEINLINE float GetDeltaTime() const
		{
			return deltaTime;
		}
		FORCEINLINE float GetElapsedTime() const
		{
			return elapsedTime;
		}
		FORCEINLINE float GetInstantFPS() const
		{
			return fps;
		}
		// Use for display
		FORCEINLINE float GetSmoothedFPS() const
		{
			return smoothedFPS;
		}
		FORCEINLINE void SetTimerScale(const float& _timeScale)
		{
			timeScale = _timeScale;
		}
		FORCEINLINE void SetMaxFrameRate(const unsigned short& _fps)
		{
			maxFrameRate = _fps;
		}
		FORCEINLINE unsigned short GetMaxFrameRate() const
		{
			return maxFrameRate;
		}
		

	public:
		TimerManager();
		~TimerManager();

		void AddTimer(Timer* _timer);
		void RemoveTimer(Timer* _timer);

		std::string GetCurrentRealTime() const;

		float Update();

		void Pause();
		void Resume();
		void Stop();
	};
}