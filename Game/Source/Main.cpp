#include "Engine.h"
#include "actors/Actor.h"
#include "utils/Math.h"

void InitConfig()
{
#ifdef _MSC_VER
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	engine::Logger::Init();
}

int main()
{
	std::cout << engine::Color::red.r << std::endl;
	std::cout << engine::Color::red.g << std::endl;
	std::cout << engine::Color::red.b << std::endl;
	std::cout << engine::Color::red.a << std::endl;

	try
	{
		engine::Angle _angle(engine::Math<float>::pi);
		engine::Angle _angle2(engine::Math<float>::pi * -3.5f);
		engine::FMath::Sqrt(-4);

		std::cout << _angle.SmallestDifferenceRadians(_angle2) << std::endl;

		engine::Engine _engine = engine::Engine(new engine::Level("first level"));
		_engine.onEngineStart.AddListener(InitConfig);
		_engine.onEngineStop.AddListener(engine::Logger::Shutdown);
		_engine.Start();
	}
	catch (const engine::Exception& _exception)
	{
		std::cerr << TXT_DARK_RED << _exception.What() << COLOR_RESET << std::endl;
	}

	return EXIT_SUCCESS;
}