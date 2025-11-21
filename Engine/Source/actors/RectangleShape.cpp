#include "RectangleShape.h"

engine::RectangleShape::RectangleShape(const FVector2& _size)
{
    shape = std::make_unique<sf::RectangleShape>(sf::Vector2f(_size.x, _size.y));
}
