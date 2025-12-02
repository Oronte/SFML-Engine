#pragma once

namespace engine
{
	class Window;

	class IDrawable
	{
	public:
		int zOrder = 0;

		virtual void Draw(Window& _window) = 0;
	};

}