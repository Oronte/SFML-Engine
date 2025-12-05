#include "Engine.h"
#include "Managers/TimerManager.h"
#include "Graphics/Window/MainWindow.h"

using namespace engine;

Engine::Engine(Level* _level)
{
	// TODO imgui + MainWindow
	//MAIN_WINDOW.Create("EngineSFML", UVector2(1920, 1080), true);
	//const bool& _imguiInit = ImGui::SFML::Init(MAIN_WINDOW.GetRenderWindow());
	level = _level;
}

void Engine::Start()
{
	onEngineStart.Broadcast();
	level->Load();
	Update();
	Stop();
}

void Engine::Update()
{
	while (level)
	{
		const std::optional _event = level->GetWindow().PollEvent();
		//ImGui::SFML::ProcessEvent(MAIN_WINDOW.GetRenderWindow(), *MAIN_WINDOW.PollEvent());
		const float& _deltaTime = M_TIMER.Update();
		level->Update(_deltaTime);
		//MAIN_WINDOW.RenderGui();

		if (_event.has_value() && _event->is<sf::Event::Closed>())
		{
			level->GetWindow().Close();
			level = nullptr;
		}
	}
}

void Engine::Stop()
{
	onEngineStop.Broadcast();
	//ImGui::SFML::Shutdown();
	delete level;
}