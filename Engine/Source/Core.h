#pragma once
#include "CoreMinimal.h"

namespace engine
{

	class Core : public IPrintable
	{
		bool isActive = false;

	public:
		FORCEINLINE virtual void SetActive(const bool& _active)
		{
			isActive = _active;
		}
		FORCEINLINE bool IsActive() const
		{
			return isActive;
		}

	public:
		virtual void Construct() = 0;
		virtual void Deconstruct() = 0;
		virtual void BeginPlay() = 0;
		virtual void EarlyTick(const float& _deltaTime) = 0;
		virtual void Tick(const float& _deltaTime) = 0;
		virtual void LateTick(const float& _deltaTime) = 0;
		virtual void BeginDestroy() = 0;

		virtual std::string ToString() const override
		{
			return std::format("Core : isActive = {}", isActive);
		}
	};


}
