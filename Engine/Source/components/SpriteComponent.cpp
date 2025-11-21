#include "SpriteComponent.h"


engine::SpriteComponent::SpriteComponent(Actor* _owner, const float& _radius, const std::string& _path, const TextureExtensionType& _textureType, const IRect& _rect, const size_t& _pointCount)
	: Component(_owner)
{
	shape = std::make_unique<ShapeObject>(_radius, _path, _textureType, _rect, _pointCount);
}

engine::SpriteComponent::SpriteComponent(Actor* _owner, const FVector2& _size, const std::string& _path, const TextureExtensionType& _textureType, const IRect& _rect, const bool& _isRepeated)
	: Component(_owner)
{
	shape = std::make_unique<ShapeObject>(_size, _path, _textureType, _rect, _isRepeated);
}

void engine::SpriteComponent::Construct()
{
	Component::Construct();
}

void engine::SpriteComponent::Deconstruct()
{
	Component::Deconstruct();
}
