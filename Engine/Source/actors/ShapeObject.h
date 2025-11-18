//#pragma once
//#include "CoreMinimal.h"
//
//namespace engine
//{
//
//	enum class TextureExtensionType
//	{
//		PNG,
//		JPG,
//		GIF
//	};
//
//	struct CircleShapeData
//	{
//		float radius;
//		std::string path;
//		sf::IntRect rect;
//		size_t pointCount;
//
//		CircleShapeData(const float _radius, const std::string& _path = "Default",
//			const sf::IntRect& _rect = sf::IntRect(), const size_t& _pointCount = 30);
//	};
//
//	struct RectangleShapeData
//	{
//		FVector2 size;
//		std::string path;
//		sf::IntRect rect;
//		TextureExtensionType textureType;
//		bool isRepeated;
//
//		RectangleShapeData(const FVector2& _size, const std::string& _path = "Default", const TextureExtensionType& _textureType = TextureExtensionType::PNG,
//			const bool _isRepeated = false, const sf::IntRect& _rect = sf::IntRect());
//	};
//
//	union ObjectData
//	{
//		std::unique_ptr<CircleShapeData> circleData;
//		std::unique_ptr<RectangleShapeData> rectangleData;
//	};
//
//	class ShapeObject
//	{
//		sf::Texture texture;
//		std::unique_ptr<sf::Shape> shape;
//		ObjectData objectData;
//
//	public:
//		ShapeObject(const CircleShapeData& _data);
//		ShapeObject(const RectangleShapeData& _data);
//	};
//
//}
//
//
//
