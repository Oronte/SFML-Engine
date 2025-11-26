#pragma once
#include "actors/ShapeObject.h"
#include "Component.h"
#include "Debuggable.h"

namespace engine
{

	class Window;

	class SpriteComponent : public Component, public IDebuggable
	{
		std::unique_ptr<ShapeObject> shape;

	public:
		FORCEINLINE ShapeObject* GetShapeObject()
		{
			return shape.get();
		}

		SpriteComponent(Actor* _owner, const float& _radius, const std::string& _path = "Default", 
			const TextureExtensionType& _textureType = TextureExtensionType::PNG, const IRect& _rect = IRect(), const size_t& _pointCount = 30);
		SpriteComponent(Actor* _owner, const FVector2& _size, const std::string& _path = "Default", 
			const TextureExtensionType& _textureType = TextureExtensionType::PNG, const IRect& _rect = IRect(), const bool& _isRepeated = false);

		virtual void Construct() override;
		virtual void Deconstruct() override;
		virtual void Tick(const float& _deltaTime) override;

		void Draw(Window& _window);
		virtual void DrawDebug(Window& _window) override;
		void SetOriginAtMiddle();
	};

}
