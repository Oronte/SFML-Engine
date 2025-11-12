#include "Component.h"
#include "actors/Actor.h"

using namespace engine;

Component::Component(Actor* _owner)
{
	owner = _owner;
}

void Component::Construct()
{
	SetActive(true);
}

void Component::Deconstruct()
{
	SetActive(false);
}