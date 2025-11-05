#include "CoreMinimal.h"
#include "time/TimerManager.h"

int main()
{
	try
	{
		int _test = 0;
		//new engine::Timer([&](){std::cout << NAME_OF(_test) << std::endl;throw engine::Exception("excp"); }, 5.f);
	}
	catch (const engine::Exception& _exception)
	{
		std::cerr << _exception.What() << std::endl;
	}
	return 0;
}