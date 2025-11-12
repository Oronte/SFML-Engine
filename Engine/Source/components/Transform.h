#pragma once
#include "actors/Transformable.h"
#include "Component.h"

namespace engine
{

	class Transform : public Component, public ITransformable
	{
		TransformData transform;

	public:
		#pragma region Getters

		FORCEINLINE virtual FVector2 GetOrigin() const override
		{
			return transform.origin;
		}
		FORCEINLINE virtual FVector2 GetPosition() const override
		{
			return transform.position;
		}
		FORCEINLINE virtual sf::Angle GetRotation() const override
		{
			return transform.rotation;
		}
		FORCEINLINE virtual FVector2 GetScale() const override
		{
			return transform.scale;
		}
		FORCEINLINE virtual TransformData GetTransform() const override
		{
			return transform;
		}

#pragma endregion

		#pragma region Setters

		FORCEINLINE virtual void SetOrigin(const FVector2& _origin) override
		{
			transform.origin = _origin;
		}
		FORCEINLINE virtual void SetPosition(const FVector2& _position) override
		{
			transform.position = _position;
		}
		FORCEINLINE virtual void SetRotation(const sf::Angle& _rotation) override
		{
			transform.rotation = _rotation;
		}
		FORCEINLINE virtual void SetScale(const FVector2& _scale) override
		{
			transform.scale = _scale;
		}
		FORCEINLINE virtual void SetTransform(const TransformData& _transformData) override
		{
			transform = _transformData;
		}
		FORCEINLINE virtual void Move(const FVector2& _offset) override
		{
			transform.position += _offset;
		}
		FORCEINLINE virtual void Rotate(const sf::Angle& _angle) override
		{
			transform.rotation += _angle;
		}
		FORCEINLINE virtual void Scale(const FVector2& _factor) override
		{
			transform.scale += _factor;
		}

#pragma endregion

	public:
		Transform(Actor* _owner, const TransformData& _transform = TransformData());
	};
}

