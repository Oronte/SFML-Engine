//#include "ShapeObject.h"
//
//using namespace engine;
//
//engine::RectangleShapeData::RectangleShapeData(const FVector2& _size, const std::string& _path, const TextureExtensionType& _textureType, const bool _isRepeated, const sf::IntRect& _rect)
//{
//	size = _size;
//	path = _path;
//	rect = _rect;
//	textureType = _textureType;
//	isRepeated = _isRepeated;
//}
//
//engine::CircleShapeData::CircleShapeData(const float _radius, const std::string& _path, const sf::IntRect& _rect, const size_t& _pointCount)
//{
//	radius = _radius;
//	path = _path;
//	rect = _rect;
//	pointCount = _pointCount;
//}
//
//engine::ShapeObject::ShapeObject(const CircleShapeData& _data)
//{
//	texture = sf::Texture();
//	objectData.circleData = std::make_unique<CircleShapeData>(_data.radius, _data.path, _data.rect, _data.pointCount);
//	shape = std::make_unique<sf::Shape>(_data.radius, _data.pointCount);
//	// TODO Texture Manager
//}
//
//engine::ShapeObject::ShapeObject(const RectangleShapeData& _data)
//{
//	texture = Texture();
//	objectData.rectangleData = std::make_unique<CircleShapeData>(_data.size, _data.path, _data.textureType, _data.rect, _data.pointCount);
//	InitRectangle(*objectData.data.rectangleData);
//}
