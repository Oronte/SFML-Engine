#pragma once
#include "CoreMinimal.h"

namespace engine
{
	struct TransformData
	{
		FVector2 position;
		sf::Angle rotation;
		FVector2 scale;
		FVector2 origin;

		TransformData()
		{
			origin = position = FVector2();
			rotation = sf::Angle();
			scale = FVector2(1.0f);
		}
		TransformData(const FVector2& _position, const sf::Angle& _rotation, const FVector2& _scale = FVector2(1.0f))
		{
			origin = FVector2();
			position = _position;
			rotation = _rotation;
			scale = _scale;
		}
		TransformData(const FVector2& _origin, const FVector2& _position,
			const sf::Angle& _rotation, const FVector2& _scale = FVector2(1.0f))
		{
			origin = _origin;
			position = _position;
			rotation = _rotation;
			scale = _scale;
		}
	};

	class ITransformable
	{
	public:

		//Get
		FORCEINLINE virtual FVector2 GetOrigin() const = 0;
		FORCEINLINE virtual FVector2 GetPosition() const = 0;
		FORCEINLINE virtual sf::Angle GetRotation() const = 0;
		FORCEINLINE virtual FVector2 GetScale() const = 0;
		FORCEINLINE virtual TransformData GetTransform() const = 0;


		//Set
		FORCEINLINE virtual void SetPosition(const FVector2& _position) = 0;
		FORCEINLINE virtual void SetRotation(const sf::Angle& _rotation) = 0;
		FORCEINLINE virtual void SetScale(const FVector2& _scale) = 0;
		FORCEINLINE virtual void SetOrigin(const FVector2& _origin) = 0;
		FORCEINLINE virtual void SetTransform(const TransformData& _transformData)
		{
			SetPosition(_transformData.position);
			SetRotation(_transformData.rotation);
			SetScale(_transformData.scale);
			SetOrigin(_transformData.origin);
		}
		FORCEINLINE virtual void Move(const FVector2& _offset) = 0;
		FORCEINLINE virtual void Rotate(const sf::Angle& _angle) = 0;
		FORCEINLINE virtual void Scale(const FVector2& _factor) = 0;
	};

}