#include "Engine.h"
#include "time/TimerManager.h"

using namespace engine;

Engine::Engine(Level* _level)
{
	level = _level;
}

void Engine::Start()
{
	onEngineStart.Broadcast();
	onEngineStart.Broadcast();
	Update();
	Stop();
}

void Engine::Update()
{
	while (level)
	{
		const float& _deltaTime = M_TIMER.Update();
		level->Update(_deltaTime);
	}
}

void Engine::Stop()
{
	onEngineStop.Broadcast();
	delete level;
}