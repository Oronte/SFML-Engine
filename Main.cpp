#include "CoreMinimal.h"
#include "time/TimerManager.h"
#include "Vector2.h"

int main()
{
	try
	{
		engine::FVector2 _vector = engine::FVector2(sf::Vector2f(1, 2));
		std::cout << _vector;
		int _test = 0;
		//new engine::Timer([&](){std::cout << NAME_OF(_test) << std::endl;throw engine::Exception("excp"); }, 5.f);
	}
	catch (const engine::Exception& _exception)
	{
		std::cerr << _exception.What() << std::endl;
	}
	return 0;
}