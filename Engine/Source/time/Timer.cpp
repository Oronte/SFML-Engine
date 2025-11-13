#include "Timer.h"
#include "TimerManager.h"

using namespace engine;

Timer::Timer(const std::function<void()>& _callback, const float& _duration, const bool _startRunning,
	const bool _isLoop)
{
	isToDelete = false;
	isRunning = _startRunning;
	isLoop = _isLoop;
	currentTime = 0.0;
	duration = _duration;
	callback = _callback;

	TimerManager::GetInstance().AddTimer(this);
}

void Timer::Start()
{
	onStart.Broadcast();
	Reset();
	Resume();
}

void Timer::Update(const float& _deltaTime)
{
	if (!isRunning) return;

	currentTime += _deltaTime;

	if (currentTime >= duration)
	{
		if (callback) callback();

		if (!isLoop) Stop();

		Reset();
	}
}

void Timer::Stop()
{
	onStop.Broadcast();

	Pause();
	isToDelete = true;
}

void Timer::Resume()
{
	onResume.Broadcast();
	isRunning = true;
}

void Timer::Reset()
{
	onReset.Broadcast();
	currentTime = 0.0f;
}

void Timer::Pause()
{
	onPause.Broadcast();
	isRunning = false;
}