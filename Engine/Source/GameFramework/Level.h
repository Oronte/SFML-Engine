#pragma once
#include "Graphics/Window/Window.h"
#include "Managers/ActorManager.h"
#include "Managers/CameraManager.h"

namespace engine
{

	class Level
	{
		std::string name;
		Window window;
		CameraManager cameraManager;
		ActorManager actorManager;
		Color backgroundColor = Color::Black();

	public:
		Level(const std::string& _name, const UVector2& _windowSize = UVector2(1920, 1080),
			const bool& _isFullscreen = false);

		FORCEINLINE bool IsActive() const
		{
			return window.IsOpen();
		}
		FORCEINLINE Window& GetWindow()
		{
			return window;
		}
		FORCEINLINE UVector2 GetWindowSize() const
		{
			return window.GetSize();
		}
		CameraManager& GetCameraManager()
		{
			return cameraManager;
		}
		ActorManager& GetActorManager()
		{
			return actorManager;
		}

	public:
		virtual void Load();
		void Update(const float& _deltaTime);
	};

}