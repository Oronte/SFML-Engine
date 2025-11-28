#include "Engine.h"
#include "Managers/TimerManager.h"
#include "Graphics/Window/MainWindow.h"

using namespace engine;

Engine::Engine(Level* _level)
{
	MAIN_WINDOW.Create("EngineSFML", UVector2(1920, 1080), true);
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
		/*ImGui::SFML::ProcessEvent(MAIN_WINDOW.GetRenderWindow(), *MAIN_WINDOW.PollEvent());
		ImGui::ShowDemoWindow();
		ImGui::Begin("Hello");
		ImGui::Text("Salut depuis ImGui + SFML 3");
		ImGui::Button("Clique");
		ImGui::End();*/
		const float& _deltaTime = M_TIMER.Update();
		level->Update(_deltaTime);
		MAIN_WINDOW.RenderGui();
	}
}

void Engine::Stop()
{
	onEngineStop.Broadcast();
	//ImGui::SFML::Shutdown();
	delete level;
}