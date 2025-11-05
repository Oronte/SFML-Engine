#include "Timer.h"
#include "TimerManager.h"

using namespace engine;

Timer::Timer(const std::function<void()>& _callback, const float& _duration, const bool _startRunning,
	const bool _isLoop)
{
	TimerManager& _manager = TimerManager::GetInstance();

	isToDelete = false;
	isRunning = _startRunning;
	isLoop = _isLoop;
	currentTime = 0.0;
	duration = _duration;
	callback = _callback;

	_manager.AddTimer(this);
}

void Timer::Start()
{
	Reset();
	Resume();
}

void Timer::Update(const float& _deltaTime)
{
	if (!isRunning) return;

	currentTime += _deltaTime;

	if (currentTime >= duration)
	{
		if (callback)
		{
			callback();
		}

		if (!isLoop)
		{
			Stop();
		}

		Reset();
	}
}

void Timer::Stop()
{
	Pause();
	isToDelete = true;
}

void Timer::Resume()
{
	isRunning = true;
}

void Timer::Reset()
{
	currentTime = 0.0f;
}

void Timer::Pause()
{
	isRunning = false;
}