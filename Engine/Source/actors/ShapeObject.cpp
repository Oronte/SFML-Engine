#include "ShapeObject.h"

using namespace engine;



engine::ShapeObject::ShapeObject(const float& _radius, const std::string& _path, const IRect& _rect, const size_t& _pointCount)
{
	shape = std::make_unique<sf::CircleShape>(_radius, _pointCount);
	// TODO Texture Manager
}

engine::ShapeObject::ShapeObject(const FVector2& _size, const std::string& _path, const TextureExtensionType& _textureType, const bool& _isRepeated, const IRect& _rect)
{
	shape = std::make_unique<sf::RectangleShape>(_size);
	// TODO Texture Manager
}
