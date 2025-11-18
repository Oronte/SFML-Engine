#include "Actor.h"
#include "Transform.h"


engine::Actor::Actor()
{
	transform = std::make_unique<Transform>();
}

void engine::Actor::SetActive(const bool& _status)
{
	for (std::pair<const std::type_index, std::unique_ptr<Component>>& _pair : components)
	{
		_pair.second->SetActive(_status);
	}
}

void engine::Actor::Construct()
{
	for (std::pair<const std::type_index, std::unique_ptr<Component>>& _pair : components)
	{
		_pair.second->Construct();
	}
}

void engine::Actor::Deconstruct()
{
	for (std::pair<const std::type_index, std::unique_ptr<Component>>& _pair : components)
	{
		_pair.second->Deconstruct();
	}
}

void engine::Actor::BeginPlay()
{
	for (std::pair<const std::type_index, std::unique_ptr<Component>>& _pair : components)
	{
		_pair.second->BeginPlay();
	}
}

void engine::Actor::EarlyTick(const float& _deltaTime)
{
	for (std::pair<const std::type_index, std::unique_ptr<Component>>& _pair : components)
	{
		_pair.second->EarlyTick(_deltaTime);
	}
}

void engine::Actor::Tick(const float& _deltaTime)
{
	for (std::pair<const std::type_index, std::unique_ptr<Component>>& _pair : components)
	{
		_pair.second->SetActive(_deltaTime);
	}
}

void engine::Actor::LateTick(const float& _deltaTime)
{
	for (std::pair<const std::type_index, std::unique_ptr<Component>>& _pair : components)
	{
		_pair.second->LateTick(_deltaTime);
	}
}

void engine::Actor::BeginDestroy()
{
	for (std::pair<const std::type_index, std::unique_ptr<Component>>& _pair : components)
	{
		_pair.second->BeginDestroy();
	}
	components.clear();
}
