#include "ShapeObject.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "TextureManager.h"

using namespace engine;


engine::ShapeObject::ShapeObject(const float& _radius, const std::string& _path, const TextureExtensionType& _textureType, const IRect& _rect, const size_t& _pointCount)
{
	shapeType = ShapeType::Circle;
	shape = std::make_unique<CircleShape>(_radius, _pointCount);
	M_TEXTURE.Load(this, _path, _textureType);
}

engine::ShapeObject::ShapeObject(const FVector2& _size, const std::string& _path, const TextureExtensionType& _textureType, const IRect& _rect, const bool& _isRepeated)
{
	shapeType = ShapeType::Rectangle;
	shape = std::make_unique<RectangleShape>(_size);
	M_TEXTURE.Load(this, _path, _textureType);
}
