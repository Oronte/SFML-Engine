#include "Engine.h"
#include "time/TimerManager.h"

void InitConfig()
{
#ifdef _MSC_VER
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	engine::Logger::Init();
}

void Test()
{
	LOG(engine::VerbosityType::Display, "Timer");
}

void StartGame()
{
	std::unique_ptr<engine::Level> _level = std::make_unique<engine::Level>("first level");
	engine::Engine _engine = engine::Engine(_level.get());

	std::unique_ptr<engine::Actor> _actor = std::make_unique<engine::Actor>(_level.get());
	_level->GetActorManager().AddActor(_actor.get());

	M_TIMER.CreateTimer( Test , 2.f, true, true);

	_engine.onEngineStart.AddListener(InitConfig);
	_engine.onEngineStop.AddListener(engine::Logger::Shutdown);
	_engine.Start();
}

int main()
{

	try
	{

		StartGame();
	}
	catch (const engine::Exception& _exception)
	{
		std::cerr << TXT_DARK_RED << _exception.What() << COLOR_RESET << std::endl;
	}

	return EXIT_SUCCESS;
}