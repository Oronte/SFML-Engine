#include "SpriteComponent.h"
#include "Window.h"
#include "actors/Actor.h"
#include "Level.h"

engine::SpriteComponent::SpriteComponent(Actor* _owner, const float& _radius, const std::string& _path, const TextureExtensionType& _textureType, const IRect& _rect, const size_t& _pointCount)
	: Component(_owner)
{
	shape = std::make_unique<ShapeObject>(_radius, _path, _textureType, _rect, _pointCount);
}

engine::SpriteComponent::SpriteComponent(Actor* _owner, const FVector2& _size, const std::string& _path, const TextureExtensionType& _textureType, const IRect& _rect, const bool& _isRepeated)
	: Component(_owner)
{
	shape = std::make_unique<ShapeObject>(_size, _path, _textureType, _rect, _isRepeated);
}

void engine::SpriteComponent::Construct()
{
	Component::Construct();

	SetOriginAtMiddle();
	owner->GetLevel()->GetCameraManager().AddToWindow(this); // TODO zOrder
}

void engine::SpriteComponent::Deconstruct()
{
	Component::Deconstruct();

	owner->GetLevel()->GetCameraManager().RemoveToWindow(this);
}

void engine::SpriteComponent::Draw(Window& _window)
{
	if (!isActive) return;
	_window.Draw(*shape);
}

void engine::SpriteComponent::SetOriginAtMiddle()
{
	owner->transform.origin = shape->GetShape()->GetGeometricCenter();
}
