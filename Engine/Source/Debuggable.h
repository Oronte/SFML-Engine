#pragma once

namespace engine
{

	class Window;

	class IDebuggable
	{
	public:
		bool useDebug = false;

	protected:
		virtual void DrawDebug(Window& _window) = 0;
	};

}