#include "Level.h"

using namespace engine;


engine::Level::Level(const std::string& _name, const UVector2& _windowSize, const bool& _isFullscreen)
{
	name = _name;
	const UVector2& _size = _isFullscreen ? UVector2(1920, 1080) : _windowSize;
	window.create(sf::VideoMode(_size),
		CAST(sf::String, name.c_str()),
		CAST(sf::State, _isFullscreen));
}

void Level::Update()
{
	window.clear();
	window.display();
}
