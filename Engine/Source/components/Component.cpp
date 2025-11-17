#include "Component.h"
#include "actors/Actor.h"
#include "Transform.h"

using namespace engine;

Transform* Component::GetTransform() const
{
	return owner ? owner->GetTransform() : nullptr;
}

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
