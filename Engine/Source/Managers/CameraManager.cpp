#include "CameraManager.h"

void engine::CameraManager::Render(Window& _window, const bool& splitScreen)
{
	for (std::pair<int, std::vector<SpriteComponent*>> _pair : drawer)
	{
		const std::vector<SpriteComponent*>& _sprites = _pair.second;

		for (SpriteComponent* _sprite : _sprites) _sprite->Draw(_window);
	}
	
}
