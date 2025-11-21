#include "ActorManager.h"

engine::ActorManager::ActorManager()
{
}

engine::ActorManager::~ActorManager()
{
}

void engine::ActorManager::BeginPlay()
{
	for (Actor* _actor : actors) _actor->BeginPlay();
}

void engine::ActorManager::Update(const float& _deltaTime)
{
	for (Actor* _actor : actors)
	{
		// TODO garbage collector
		//if (_actor->IsToDelete())
		//{
		//	RemoveActor(_actor);
		//	garbage.push_back(_actor);
		//	continue;
		//}
		if (_actor->IsActive()) _actor->Tick(_deltaTime);
	}
}

void engine::ActorManager::BeginDestroy()
{
	for (Actor* _actor : actors)
	{
		_actor->BeginDestroy();
	}
}
