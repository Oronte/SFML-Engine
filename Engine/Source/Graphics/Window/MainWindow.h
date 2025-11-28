#pragma once
#include "Window.h"

#define MAIN_WINDOW engine::MainWindow::GetInstance()

namespace engine
{

	class MainWindow : public Window, public Singleton<MainWindow>
	{
	public:
		MainWindow() {}

		INLINE void RenderGui()
		{
			//ImGui::SFML::Render(GetRenderWindow());
		}
	};

}