#include "Transform.h"

using namespace engine;

engine::Transform::Transform()
{
	origin = position = FVector2();
	rotation = sf::Angle();
	scale = FVector2(1.0f);
}

engine::Transform::Transform(const FVector2& _position, const sf::Angle& _rotation, const FVector2& _scale)
{
	origin = FVector2();
	position = _position;
	rotation = _rotation;
	scale = _scale;
}

engine::Transform::Transform(const FVector2& _origin, const FVector2& _position, const sf::Angle& _rotation, const FVector2& _scale)
{
	origin = _origin;
	position = _position;
	rotation = _rotation;
	scale = _scale;
}

std::string engine::Transform::ToString() const
{
	return std::format("Position = {} | Rotation (degrees) = {} | Scale = {} | Origin = {}",
		position.ToString(),
		rotation.asDegrees(),
		scale.ToString(),
		origin.ToString());
}
