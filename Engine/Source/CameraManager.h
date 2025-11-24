#pragma once
#include "components/CameraComponent.h"
#include "components/SpriteComponent.h"
#include "actors/Actor.h"

namespace engine
{

	class CameraManager
	{
		CameraComponent* current;
		std::map<int, std::vector<SpriteComponent*>> drawer;

	public:
		FORCEINLINE void SetCurrent(CameraComponent* _camera)
		{
			if (!_camera) return;
			current = _camera;
		}
		FORCEINLINE void AddToWindow(SpriteComponent* _sprite)
		{
			if (!_sprite)
			{
				LOG(VerbosityType::Error, "You try to add to window an invalide sprite");
				return;
			}
			drawer[_sprite->GetOwner()->GetZOrder()].push_back(_sprite);
		}
		FORCEINLINE void RemoveToWindow(SpriteComponent* _sprite)
		{
			if (!_sprite)
			{
				LOG(VerbosityType::Error, "You try to remove to window an nullptr sprite");
				return;
			} // TODO fix
			//drawer.erase(std::remove(drawer.begin(), drawer.end(), _sprite), drawer.end());
		}

		CameraManager() {}

	public:
		void Render(Window& _window, const bool& splitScreen);
	};

}

