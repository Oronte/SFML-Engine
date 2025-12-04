#include "Core/Engine.h"
#include "Actors/SpriteActor.h"
#include "Actors/SoftBodyActor.h"
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

	//engine::SpriteActor* _actor = _level->GetActorManager().CreateActor<engine::SpriteActor>(_level.get(), engine::FVector2(200.f), "Player", engine::TextureExtensionType::PNG, engine::IRect());
	//_actor->transform.position += engine::FVector2(200.f, 540.f);
	//_actor->transform.rotation = engine::Angle(50.f, true);
	//_actor->GetComponent<engine::SpriteComponent>()->useDebug = true;
	//
	//engine::SpriteActor* _defaultActor = _level->GetActorManager().CreateActor<engine::SpriteActor>(_level.get(), 50.f);
	//_defaultActor->GetComponent<engine::SpriteComponent>()->useDebug = true;
	//_defaultActor->transform.position = engine::FVector2(1600.f, 300.f);
	


	engine::SoftBodyActor* softActor = _level->GetActorManager().CreateActor<engine::SoftBodyActor>(
		_level.get(), 80.f, 20 /*pointCount*/
	);
	softActor->transform.position = engine::FVector2(600.f, 600.f);
	softActor->GetSoftBody()->PinParticle(0, true);

	// exemple : actor soft body grille
	engine::SoftBodyActor* softGrid = _level->GetActorManager().CreateActor<engine::SoftBodyActor>(
		_level.get(), engine::FVector2(200.f, 120.f), 10 /*w*/, 6 /*h*/
	);
	softGrid->transform.position = engine::FVector2(600.f, 300.f);
	softGrid->GetSoftBody()->PinParticle(0, true);

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