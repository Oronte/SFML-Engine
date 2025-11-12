#include "Engine.h"

int main()
{
	try
	{
		engine::Engine _engine = engine::Engine(new engine::Level("first level"));
		_engine.Start();
	}
	catch (const engine::Exception& _exception)
	{
		std::cerr << DARK_RED << _exception.What() << COLOR_RESET << std::endl;
	}

	return EXIT_SUCCESS;
}