#pragma once
#include "Actor.h"
#include "Components/SpriteComponent.h"
#include "Components/CameraComponent.h"
#include "Managers/TextureManager.h"

namespace engine
{

	class SpriteActor : public Actor
	{
		SpriteComponent* sprite;

	public:
		FORCEINLINE SpriteComponent* GetSprite() const
		{
			return sprite;
		}
		FORCEINLINE void SetTextureRect(const IVector2& _start, const IVector2& _size)
		{
			M_TEXTURE.SetTextureRect(sprite->GetShapeObject()->GetShape(), _start, _size);
		}
		FORCEINLINE void SetTextureRect(const IRect& _rect)
		{
			M_TEXTURE.SetTextureRect(sprite->GetShapeObject()->GetShape(), _rect);
		}

		SpriteActor(Level* _level, const FVector2& _size, const std::string& _path = "Default",
			const TextureExtensionType& _textureType = TextureExtensionType::PNG, const IRect& _rect = IRect(), 
			const bool& _isRepeated = false);
		SpriteActor(Level* _level, const float& _radius, const std::string& _path = "Default",
			const TextureExtensionType& _textureType = TextureExtensionType::PNG, const IRect& _rect = IRect(),
			const size_t& _pointCount = 30);
	};


}
