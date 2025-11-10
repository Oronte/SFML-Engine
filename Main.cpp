#include "CoreMinimal.h"
#include "Level.h"
//#include "time/TimerManager.h"


int main()
{
	try
	{
		engine::FVector2 _vector = engine::FVector2(sf::Vector2f(1, 2));
		engine::FVector2 _other = engine::FVector2(5);
		std::cout << _vector << std::endl;

		engine::Level _level = engine::Level("First Level", engine::UVector2(1000), true);

		while (_level.IsActive())
		{
			_level.Update();
		}

		int _test = engine::Math::InvSqrt(-1345.f);

		//std::cout << _vector.LengthSquared();
		//std::cout << _vector.Length();
		//std::cout << _vector.Normalized();
		//std::cout << _vector.Dot(_other);
		//std::cout << _vector.Cross(_other);
		//std::cout << _vector.Perp();
		//std::cout << _vector.DistanceSquared(_other);
		//std::cout << _vector.Distance(_other);
		//std::cout << _vector.ClampMagnitude(3);
		//std::cout << _vector.MoveTowards(_other, 3);
		//std::cout << _vector.Reflect(_other);
		//std::cout << _vector.Project(_other);
		//std::cout << _vector.AtanToRadian();
		//std::cout << _vector.AngleBetweenRadians(_other);
		//std::cout << _vector.SignedAngleDeg(_other);
		//std::cout << _vector.Rotated(3);
		//std::cout << _vector.RotatedDeg(3);
		//std::cout << _vector.RotateAround(_other, 3);
		//std::cout << _vector.Lerp(_other, 3);
		//std::cout << _vector.ClosestPointOnSegment(_other, _other);
		//std::cout << _vector.DistanceToSegment(_other, _other);
		//std::cout << _vector.SignedDistanceToLine(_other, _other);
		//std::cout << _vector.IsOnSegment(_other, _other);



		//new engine::Timer([&](){std::cout << NAME_OF(_test) << std::endl;throw engine::Exception("excp"); }, 5.f);
	}
	catch (const engine::Exception& _exception)
	{
		std::cerr << DARK_RED << _exception.What() << COLOR_RESET << std::endl;
	}
	return 0;
}