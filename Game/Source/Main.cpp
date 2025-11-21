#include "Engine.h"
#include "Texture.h"

void InitConfig()
{
#ifdef _MSC_VER
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	engine::Logger::Init();
}

int main()
{

	try
	{
		InitConfig();
		engine::Logger::Shutdown();

		//engine::Engine _engine = engine::Engine(new engine::Level("first level"));
		//_engine.onEngineStart.AddListener(InitConfig);
		//_engine.onEngineStop.AddListener(engine::Logger::Shutdown);
		//_engine.Start();
	}
	catch (const engine::Exception& _exception)
	{
		std::cerr << TXT_DARK_RED << _exception.What() << COLOR_RESET << std::endl;
	}

	return EXIT_SUCCESS;
}