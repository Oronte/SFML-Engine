#pragma once
#include "CoreMinimal.h"

namespace engine
{

	enum class TextureExtensionType
	{
		PNG,
		JPG,
		GIF
	};

	class ShapeObject
	{
		sf::Texture texture;
		std::unique_ptr<sf::Shape> shape;

	public:
		// Circle
		ShapeObject(const float& _radius, const std::string& _path = "Default",
			const IRect& _rect = IRect(), const size_t& _pointCount = 30);
		// Rectangle
		ShapeObject(const FVector2& _size, const std::string& _path = "Default", const TextureExtensionType& _textureType = TextureExtensionType::PNG,
			const bool& _isRepeated = false, const IRect& _rect = IRect());
	};

}



