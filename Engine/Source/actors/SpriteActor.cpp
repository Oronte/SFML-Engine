#include "SpriteActor.h"
#include "Level.h"

engine::SpriteActor::SpriteActor(Level* _level, const FVector2& _size, const std::string& _path, const TextureExtensionType& _textureType, const IRect& _rect, const bool& _isRepeated)
	: Actor(_level)
{
	sprite = CreateComponent<SpriteComponent>(_size, _path, _textureType, _rect, _isRepeated);
}

engine::SpriteActor::SpriteActor(Level* _level, const float& _radius, const std::string& _path, const TextureExtensionType& _textureType, const IRect& _rect, const size_t& _pointCount)
	: Actor(_level)
{
	sprite = CreateComponent<SpriteComponent>(_radius, _path, _textureType, _rect, _pointCount);
}
