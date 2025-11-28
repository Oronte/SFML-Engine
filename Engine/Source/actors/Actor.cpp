#include "Actor.h"
#include "GameFramework/Level.h"


engine::Actor::Actor(Level* _level)
{
	level = _level;
}

void engine::Actor::SetActive(const bool& _status)
{
	Core::SetActive(_status);

	for (const std::unique_ptr<Component>& _component : components)
	{
		_component->SetActive(_status);
	}
}

void engine::Actor::Construct()
{
	for (const std::unique_ptr<Component>& _component : components)
	{
		_component->Construct();
	}
}

void engine::Actor::Deconstruct()
{
	for (const std::unique_ptr<Component>& _component : components)
	{
		_component->Deconstruct();
	}
}

void engine::Actor::BeginPlay()
{
	for (const std::unique_ptr<Component>& _component : components)
	{
		_component->BeginPlay();
	}
}

void engine::Actor::Tick(const float& _deltaTime)
{
	for (const std::unique_ptr<Component>& _component : components)
	{
		_component->Tick(_deltaTime);
	}
}

void engine::Actor::BeginDestroy()
{
	for (const std::unique_ptr<Component>& _component : components)
	{
		_component->BeginDestroy();
	}
	components.clear();
}

void engine::Actor::Destroy()
{
	toDelete = true;
}
