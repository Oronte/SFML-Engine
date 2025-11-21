#include "Level.h"

using namespace engine;


engine::Level::Level(const std::string& _name, const UVector2& _windowSize, const bool& _isFullscreen)
{
	name = _name;
	window.Create(name, _windowSize, _isFullscreen);
}

void Level::Update(const float& _deltaTime)
{
	window.Clear(Color::Black());
	cameraManager.Render(window, false); // TODO SplitScreen
	window.Display();
}
