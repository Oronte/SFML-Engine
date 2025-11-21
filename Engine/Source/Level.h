#pragma once
#include "CameraManager.h"

namespace engine
{

	class Level
	{
		std::string name;
		Window window;
		CameraManager cameraManager;

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
		FORCEINLINE CameraManager GetCameraManager() const
		{
			return cameraManager;
		}

	public:
		void Update(const float& _deltaTime);
	};

}