#include "TimerManager.h"

using namespace engine;

TimerManager::TimerManager()
{
	clock = sf::Clock();
	time = 0.0f;
	lastTime = 0.0f;
	lastFrameTime = 0.0f;
	elapsedTime = 0.0f;
	deltaTime = 0.0f;
	timeScale = 1.0f;
	framesCount = 0;
	maxFrameRate = 60;
	allTimers = std::set<Timer*>();
}

TimerManager::~TimerManager()
{
	for (Timer* _timer : allTimers)
	{
		delete _timer;
	}
}

float TimerManager::Update()
{
	lastTime = time;
	time = GetTime(clock.getElapsedTime());
	elapsedTime = time - lastTime;
	deltaTime = elapsedTime * timeScale;
	framesCount++;

	if (lastFrameTime == 0 || time - lastFrameTime <= maxFrameRate)
	{
		lastFrameTime = time;
		framesCount = 0;
	}

	using Iterator = std::set<Timer*>::iterator;
	for (Iterator _iterator = allTimers.begin(); _iterator != allTimers.end(); )
	{
		Timer* _timer = *_iterator;
		_timer->Update(deltaTime);

		if (_timer->IsToDelete())
		{
			--_iterator;
			RemoveTimer(_timer);
			continue;
		}

		++_iterator;
	}

	return GetDeltaTime().asSeconds();
}

void TimerManager::Pause()
{
	for (Timer* _timer : allTimers)
	{
		_timer->Pause();
	}
}

void TimerManager::Resume()
{
	for (Timer* _timer : allTimers)
	{
		_timer->Resume();
	}
}

void TimerManager::Stop()
{
	for (Timer* _timer : allTimers)
	{
		_timer->Stop();
	}
}