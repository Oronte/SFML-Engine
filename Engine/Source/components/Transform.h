#pragma once
#include "Transformable.h"

namespace engine
{

	class Transform : public ITransformable, public IPrintable
	{
		FVector2 position;
		sf::Angle rotation;
		FVector2 scale;
		FVector2 origin;


	public:
		#pragma region Getters

		FORCEINLINE virtual FVector2 GetOrigin() const override
		{
			return origin;
		}
		FORCEINLINE virtual FVector2 GetPosition() const override
		{
			return position;
		}
		FORCEINLINE virtual sf::Angle GetRotation() const override
		{
			return rotation;
		}
		FORCEINLINE virtual FVector2 GetScale() const override
		{
			return scale;
		}

		#pragma endregion

		#pragma region Setters

		FORCEINLINE virtual void SetOrigin(const FVector2& _origin) override
		{
			origin = _origin;
		}
		FORCEINLINE virtual void SetPosition(const FVector2& _position) override
		{
			position = _position;
		}
		FORCEINLINE virtual void SetRotation(const sf::Angle& _rotation) override
		{
			rotation = _rotation;
		}
		FORCEINLINE virtual void SetScale(const FVector2& _scale) override
		{
			scale = _scale;
		}
		FORCEINLINE virtual void Move(const FVector2& _offset) override
		{
			position += _offset;
		}
		FORCEINLINE virtual void Rotate(const sf::Angle& _angle) override
		{
			rotation += _angle;
		}
		FORCEINLINE virtual void Scale(const FVector2& _factor) override
		{
			scale += _factor;
		}

		#pragma endregion

	public:
		Transform();
		Transform(const FVector2& _position, const sf::Angle& _rotation, const FVector2& _scale = FVector2(1.0f));
		Transform(const FVector2& _origin, const FVector2& _position,
			const sf::Angle& _rotation, const FVector2& _scale = FVector2(1.0f));


		virtual std::string ToString() const override;
	};
}

