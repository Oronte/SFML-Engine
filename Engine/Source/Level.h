#pragma once
#include "CoreMinimal.h"

namespace engine
{

	class Level
	{
		std::string name;
		sf::RenderWindow window;

	public:
		Level(const std::string& _name, const UVector2& _windowSize = UVector2(1920, 1080),
			const bool& _isFullscreen = false);

		FORCEINLINE bool IsActive() const
		{
			return window.isOpen();
		}
		FORCEINLINE sf::RenderWindow& GetRenderWindow()
		{
			return window;
		}
		FORCEINLINE FVector2 GetWindowSize() const
		{
			return CAST(FVector2, window.getSize());
		}

	public:
		void Update(const float _deltaTime);
	};

}