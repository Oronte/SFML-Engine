#include "TimerManager.h"

using namespace engine;

engine::TimerManager::~TimerManager()
{
	allTimers.clear();
}

void engine::TimerManager::AddTimer(Timer* _timer)
{
	if (!_timer)
	{
		LOG(VerbosityType::Error, "Try to add nullptr timer");
		return;
	}

	allTimers.emplace_back(std::unique_ptr<Timer>(_timer));
}

void engine::TimerManager::RemoveTimer(Timer* _timer)
{
	if (!_timer)
	{
		LOG(VerbosityType::Error, "Try to remove nullptr timer");
		return;
	}

	std::vector<std::unique_ptr<Timer>>::iterator _iterator =
		std::find_if(allTimers.begin(), allTimers.end(),
		[&](const std::unique_ptr<Timer>& _currentTimer) { return _currentTimer.get() == _timer; });

	if (_iterator == allTimers.end()) return;

	(*_iterator)->Stop();
	allTimers.erase(_iterator);
}

std::string engine::TimerManager::GetCurrentRealTime() const
{
	const time_t& _now = std::time(nullptr);

	std::tm _ltm;

#ifdef _MSC_VER
	localtime_s(&_ltm, &_now);
#else
	localtime_r(&_now, &_ltm);
#endif

	const std::string& _date = TwoDigitsTime(_ltm.tm_mday) + "/" + TwoDigitsTime(1 + _ltm.tm_mon) + "/" + TwoDigitsTime(1900 + _ltm.tm_year);
	const std::string& _time = TwoDigitsTime(_ltm.tm_hour) + ":" + TwoDigitsTime(_ltm.tm_min) + ":" + TwoDigitsTime(_ltm.tm_sec);

	return _date + " " + _time;
}

float engine::TimerManager::Update()
{
	float _currentTime = GetTime(clock.getElapsedTime());

    // First frame initialization
    if (lastTimeStamp < 0.0f)
    {
        lastTimeStamp = _currentTime;
        lastFrameDuration = 0.0f;
    }
    else
    {
        lastFrameDuration = _currentTime - lastTimeStamp;
        if (lastFrameDuration < 0.0f)
            lastFrameDuration = 0.0f;
    }


    if (maxFrameRate > 0)
    {
        float _targetFrameTime = 1.0f / static_cast<float>(maxFrameRate);

        if (lastFrameDuration > 0.0f && lastFrameDuration < _targetFrameTime)
        {
            float _sleepTime = _targetFrameTime - lastFrameDuration;
            sf::sleep(sf::seconds(_sleepTime));

            // Recalculate correct timing after sleep
            float _newTime = GetTime(clock.getElapsedTime());
            lastFrameDuration = _newTime - lastTimeStamp;
            if (lastFrameDuration < 0.0f) lastFrameDuration = 0.0f;

            _currentTime = _newTime;
        }
    }


    lastTimeStamp = _currentTime;
    elapsedTime = lastFrameDuration;
    deltaTime = lastFrameDuration * timeScale;
    framesCount++;


    if (lastFrameDuration > 0.0f)
    {
        fps = 1.0f / lastFrameDuration;
        constexpr float _smoothingFactor = 0.1f;
        smoothedFPS = (1.0f - _smoothingFactor) * smoothedFPS + _smoothingFactor * fps;
    }

    for (std::vector<std::unique_ptr<Timer>>::iterator _iterator = allTimers.begin(); _iterator != allTimers.end(); )
    {
        Timer* _timer = _iterator->get();
        _timer->Update(deltaTime);

        if (_timer->IsToDelete())
        {
            _timer->Stop();
            _iterator = allTimers.erase(_iterator);
        }
        else ++_iterator;
    }

    return deltaTime;
}

void engine::TimerManager::Pause()
{
	onPauseTimer.Broadcast();

	for (std::unique_ptr<Timer>& _timer : allTimers) _timer->Pause();
}

void engine::TimerManager::Resume()
{
	onResumeTimer.Broadcast();

	for (std::unique_ptr<Timer>& _timer : allTimers) _timer->Resume();
}

void engine::TimerManager::Stop()
{
	onStopTimer.Broadcast();

	for (std::unique_ptr<Timer>& _timer : allTimers) _timer->Stop();
}