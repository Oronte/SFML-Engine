#include "Debug.h"
#include "actors/Actor.h"
#include "Window.h"
#include "Level.h"
#include "Vertices.h"

void engine::Debug::DrawDebugCircle(Actor* _context, const FVector2& _position, const float& _radius, const int& _pointCount, const Color& _color)
{
	DrawDebugCircle(_context->GetLevel()->GetWindow(), _position, _radius, _pointCount, _color);
}

void engine::Debug::DrawDebugCircle(Window& _window, const FVector2& _position, const float& _radius, const int& _pointCount, const Color& _color)
{
	Vertices _vert = Vertices(PrimitiveType::LineStrip);

	FVector2 _initialPoint = _position + FVector2(0.f, _radius);

	const float& _rotateRad = FMath::pi * 2.0f / _pointCount;
	for (int _index = 0; _index < _pointCount; _index++)
	{
		_vert.Append(_initialPoint.RotateAround(_position, _rotateRad * _index), _color);
	}

	_window.Draw(_vert);
}
