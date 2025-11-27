#include "SpriteComponent.h"
#include "Window.h"
#include "actors/Actor.h"
#include "Level.h"
#include "CameraManager.h"
#include "Vertices.h"

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

void engine::SpriteComponent::Tick(const float& _deltaTime)
{
	Component::Tick(_deltaTime);

	shape->GetShape()->SetTransform(owner->transform);
}


void engine::SpriteComponent::Draw(Window& _window)
{
	if (!isActive) return;
	_window.Draw(*shape);
	DrawDebug(_window);
}

void engine::SpriteComponent::DrawDebug(Window& _window)
{
	if (!useDebug) return;

	Vertices _vert = Vertices(PrimitiveType::LineStrip);
	Shape* _shape = shape->GetShape();
	const int& _pointCount = CAST(int, _shape->GetPointCount());
	const FVector2& _position = owner->transform.position;
	const FVector2& _origin = owner->transform.origin;
	const float& _rotation = owner->transform.rotation.ToRadians();

	switch (shape->GetShapeType())
	{
	case ShapeType::Circle:

		//for (int _index = 0; _index < _pointCount; _index++)
		//{
		//	_vert.Append(_shape->GetPoint(_index) + _position - _origin, Color::Green());
		//}
		//_vert.Append(_shape->GetPoint(0) + _position - _origin, Color::Green());

		Debug::DrawDebugCircle(_window, _position, 100.f);

		break;

	case ShapeType::Rectangle:

		if (_pointCount < 4) return;

		Vertex _firstPoint;
		_firstPoint.position = FVector2(_shape->GetPoint(0) + _position - _origin).RotateAround(_position, _rotation);
		_firstPoint.color = Color::Green();

		_vert.Append(_firstPoint);
		_vert.Append(FVector2(_shape->GetPoint(1) + _position - _origin).RotateAround(_position, _rotation), Color::Green());
		_vert.Append(FVector2(_shape->GetPoint(2) + _position - _origin).RotateAround(_position, _rotation), Color::Green());
		_vert.Append(FVector2(_shape->GetPoint(3) + _position - _origin).RotateAround(_position, _rotation), Color::Green());
		_vert.Append(_firstPoint);

		break;
	};

	_window.Draw(_vert);
}

void engine::SpriteComponent::SetOriginAtMiddle()
{
	owner->transform.origin = shape->GetShape()->GetGeometricCenter();
}

