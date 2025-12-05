#include "Core/Engine.h"
#include "Actors/SpriteActor.h"
#include "Actors/SoftBodyActor.h"
#include "GameFramework/Level.h"

void InitConfig()
{
#ifdef _MSC_VER
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
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
	

	engine::SpriteActor* _actor = _level->GetActorManager().CreateActor<engine::SpriteActor>(_level.get(), engine::FVector2(125.f, 193.75f), "RyuGifSheet", engine::TextureExtensionType::PNG, engine::IRect());
	_actor->transform.position += engine::FVector2(200.f, 540.f);
	_actor->transform.rotation = engine::Angle(50.f, true);
	_actor->GetComponent<engine::SpriteComponent>()->useDebug = true;

	//engine::SoftBodyActor* softActor = _level->GetActorManager().CreateActor<engine::SoftBodyActor>(
	//	_level.get(), 80.f, 20 /*pointCount*/
	//);
	//softActor->transform.position = engine::FVector2(600.f, 600.f);
	//softActor->GetSoftBody()->PinParticle(0, true);

	//// exemple : actor soft body grille
	//engine::SoftBodyActor* softGrid = _level->GetActorManager().CreateActor<engine::SoftBodyActor>(
	//	_level.get(), engine::FVector2(200.f, 120.f), 10 /*w*/, 6 /*h*/
	//);
	//softGrid->transform.position = engine::FVector2(600.f, 300.f);
	//softGrid->GetSoftBody()->PinParticle(0, true);

	_engine.Start();

	engine::Logger::Shutdown();
}

struct Player {
	std::string name;
	int level;
	float health;
};

int main()
{
	Player player{ "Test", 3, 0.0f };

	// ---- Sérialisation ----
	rapidjson::Document doc;
	doc.SetObject();
	rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

	doc.AddMember("name", rapidjson::Value().SetString(player.name.c_str(), allocator), allocator);
	doc.AddMember("level", player.level, allocator);
	doc.AddMember("health", player.health, allocator);

	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	//rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
	doc.Accept(writer);


	// ---- Désérialisation ----
	rapidjson::Document doc2;
	if (doc2.Parse(buffer.GetString()).HasParseError()) {
		std::cerr << "Erreur de parsing JSON!\n";
		return 1;
	}

	Player loadedPlayer;
	loadedPlayer.name = doc2["name"].GetString();
	loadedPlayer.level = doc2["level"].GetInt();
	loadedPlayer.health = doc2["health"].GetFloat();

	std::ofstream outFile("../Content/Saves/player.json");
	if (!outFile) {
	}
	else {
		outFile << buffer.GetString(); // Écrit le JSON sérialisé dans le fichier
		outFile.close();
	}

	std::ifstream inFile("../Content/Saves/player.json");
	if (!inFile) {
	}
	else {
		std::string jsonStr((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
		inFile.close();

		rapidjson::Document doc2;
		if (doc2.Parse(jsonStr.c_str()).HasParseError()) {
			return 1;
		}

		Player loadedPlayer;
		loadedPlayer.name = doc2["name"].GetString();
		loadedPlayer.level = doc2["level"].GetInt();
		loadedPlayer.health = doc2["health"].GetFloat();

		std::cout << "Player chargé depuis le fichier: "
			<< loadedPlayer.name << ", "
			<< loadedPlayer.level << ", "
			<< loadedPlayer.health << std::endl;
	}

	try
	{
		//StartGame();
	}
	catch (const engine::Exception& _exception)
	{
		std::cerr << TXT_DARK_RED << _exception.What() << COLOR_RESET << std::endl;
	}

	return EXIT_SUCCESS;
}