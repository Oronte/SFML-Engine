#include "Level.h"

int main()
{
	try
	{
		std::cout << engine::Math::Sqrt(2);
		
		//LOG(engine::VerbosityType::Display, "test");

		engine::Level _level = engine::Level("first level");
		while (_level.IsActive())
		{
			_level.Update();
		}
	}
	catch (const engine::Exception& _e)
	{
		std::cerr << DARK_RED << _e.What() << COLOR_RESET << std::endl;
	}

	return EXIT_SUCCESS;
}