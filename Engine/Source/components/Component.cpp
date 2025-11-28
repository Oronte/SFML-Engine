#include "Component.h"
#include "Actors/Actor.h"
#include "Utilities/Math/Transform.h"

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

std::string engine::Component::ToString() const
{
	if (!owner) return "Component wath no owner";
	return "Component : owner = " + owner->ToString();
}
