#pragma once
#include "Macro.h"
#include "Vector2D.h"
#include "Color.h"

namespace engine
{

	class Actor;
	class Window;

	class Debug
	{
	public:
		static void DrawDebugCircle(Actor* _context, const FVector2& _position, const float& _radius, const int& _pointCount = 12, const Color& _color = Color::Magenta());
		static void DrawDebugCircle(Window& _window, const FVector2& _position, const float& _radius, const int& _pointCount = 12, const Color& _color = Color::Magenta());

		//INLINE void DrawDebugRect(Window& _window, const FVector2& _position, const float& _radius, const int& _pointCount = 12, const Color& _color = Color::Magenta());
		//INLINE void DrawDebugRect(Window& _window, const FVector2& _position, const float& _radius, const int& _pointCount = 12, const Color& _color = Color::Magenta());
	};

}

