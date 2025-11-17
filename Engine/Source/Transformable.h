#pragma once
#include "CoreMinimal.h"

namespace engine
{

	class ITransformable
	{
	public:

		//Get
		FORCEINLINE virtual FVector2 GetOrigin() const = 0;
		FORCEINLINE virtual FVector2 GetPosition() const = 0;
		FORCEINLINE virtual sf::Angle GetRotation() const = 0;
		FORCEINLINE virtual FVector2 GetScale() const = 0;


		//Set
		FORCEINLINE virtual void SetPosition(const FVector2& _position) = 0;
		FORCEINLINE virtual void SetRotation(const sf::Angle& _rotation) = 0;
		FORCEINLINE virtual void SetScale(const FVector2& _scale) = 0;
		FORCEINLINE virtual void SetOrigin(const FVector2& _origin) = 0;
		FORCEINLINE virtual void Move(const FVector2& _offset) = 0;
		FORCEINLINE virtual void Rotate(const sf::Angle& _angle) = 0;
		FORCEINLINE virtual void Scale(const FVector2& _factor) = 0;
	};

}