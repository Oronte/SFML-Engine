#include "Level.h"


using namespace engine;


engine::Level::Level(const std::string& _name, const UVector2& _windowSize, const bool& _isFullscreen)
{
	name = _name;
	window.Create(name, _windowSize, _isFullscreen);

	window.SetIcon(Image(UVector2(1), Color::Red())); // TODO Make this cutomable
}

void Level::Load()
{
	actorManager.BeginPlay();
}

void Level::Update(const float& _deltaTime)
{
	window.Clear(backgroundColor);
	cameraManager.Render(window, false); // TODO SplitScreen
	window.Display();
	actorManager.Update(_deltaTime);
}
