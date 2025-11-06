#include "Utilities.h"

using namespace engine;

unsigned int GetUniqueID()
{
	static unsigned int _id = 0;
	return ++_id;
}

int GetRandomNumberInRange(const int& _min, const int& _max)
{
	return GetRandomNumberInRange<int>(_min, _max);
}



float Lerp_Constant(const float& _start, const float& _end, const float& _time)
{
	return 0.0f;
}

float DotProduct(const sf::Vector2f& _direction, const sf::Vector2f& _normal)
{
	return 0.0f;
}

float EaseOutQuart(const float& _time)
{
	return 0.0f;
}

sf::Vector2f ComputeNormal(const sf::FloatRect& _rect)
{
	return sf::Vector2f();
}

sf::Vector2f SmoothDamp(const sf::Vector2f& _current, sf::Vector2f _target, sf::Vector2f& _currentVelocity, float _smoothTime, const float& _deltaTime, const float& _maxSpeed)
{
	return sf::Vector2f();
}

std::vector<std::string> SplitString(const std::string& _string, const char& _delimiter)
{
	return std::vector<std::string>();
}

float Length(const sf::Vector2f& _vector)
{
	return 0.0f;
}

void Normalize(sf::Vector2f& _vector)
{
}

float Distance(const float& _first, const float& _second)
{
	return 0.0f;
}

float Distance(const sf::Vector2f& _first, const sf::Vector2f& _second)
{
	return 0.0f;
}
