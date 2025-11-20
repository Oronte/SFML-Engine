#include "TextureManager.h"

using namespace engine;

void engine::TextureManager::SetTextureRect(sf::Shape* _shape, const IVector2& _start, const IVector2& _size)
{
	SetTextureRect(_shape, IRect(_start, _size));
}

void engine::TextureManager::SetTextureRect(sf::Shape* _shape, const IRect& _rect)
{
	_shape->setTextureRect(_rect);
}
