#include "Core/Engine.h"
#include "Actors/SpriteActor.h"
#include "GameFramework/Level.h"

void InitConfig()
{
#ifdef _MSC_VER
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	engine::Logger::Init();
}

void StartGame()
{
	InitConfig();

	std::unique_ptr<engine::Level> _level = std::make_unique<engine::Level>("first level");
	engine::Engine _engine = engine::Engine(_level.get());

	engine::SpriteActor* _actor = _level->GetActorManager().CreateActor<engine::SpriteActor>(_level.get(), engine::FVector2(200.f), "Player", engine::TextureExtensionType::PNG, engine::IRect());
	engine::SpriteActor* _defaultActor = _level->GetActorManager().CreateActor<engine::SpriteActor>(_level.get(), 50.f);
	_actor->transform.position += engine::FVector2(200.f, 540.f);
	_actor->transform.rotation = engine::Angle(50.f, true);
	//_actor->transform.scale = engine::FVector2(0.5f, 0.5f);
	_actor->GetComponent<engine::SpriteComponent>()->useDebug = true;
	_defaultActor->GetComponent<engine::SpriteComponent>()->useDebug = true;
	_defaultActor->transform.position = engine::FVector2(1600.f, 300.f);
	//_defaultActor->transform.scale = engine::FVector2(0.5f);
	_engine.Start();

	engine::Logger::Shutdown();
}

int main()
{

	try
	{

		StartGame();
	}
	catch (const engine::Exception& _exception)
	{
		std::cerr << TXT_DARK_RED << _exception.What() << COLOR_RESET << std::endl;
	}

	return EXIT_SUCCESS;
}