#pragma once
#include "actors/ShapeObject.h"
#include "Component.h"

namespace engine
{

	class SpriteComponent : public Component
	{
		std::unique_ptr<ShapeObject> shape;

	public:
		SpriteComponent(Actor* _owner, const float& _radius, const std::string& _path = "Default", 
			const TextureExtensionType& _textureType = TextureExtensionType::PNG, const IRect& _rect = IRect(), const size_t& _pointCount = 30);
		SpriteComponent(Actor* _owner, const FVector2& _size, const std::string& _path = "Default", 
			const TextureExtensionType& _textureType = TextureExtensionType::PNG, const IRect& _rect = IRect(), const bool& _isRepeated = false);

		virtual void Construct() override;
		virtual void Deconstruct() override;
	};

}
