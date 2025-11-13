#include "Engine.h"
#include "utils/Event.h"

int Add(int _a, int _b)
{
	return _a + _b;
}

class MyClass
{
	int x;
public:
	MyClass(int _x) 
	{
		x = _x;
	}

	int Test(int _x, int _y)
	{
		return x + _x + _y;
	}

};

int main()
{
	try
	{
		engine::Delegate<int(int, int)> _delegate;
		_delegate.SetCallback(Add);
		MyClass _myClass = MyClass(7);
		_delegate.SetCallback(&_myClass, &MyClass::Test);
		int _test = _delegate.Broadcast(1, 2);
		std::cout << _test;

		//engine::Engine _engine = engine::Engine(new engine::Level("first level"));
		//_engine.Start();
	}
	catch (const engine::Exception& _exception)
	{
		std::cerr << DARK_RED << _exception.What() << COLOR_RESET << std::endl;
	}

	return EXIT_SUCCESS;
}