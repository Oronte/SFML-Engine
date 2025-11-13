#pragma once
#include "Core.h"

namespace engine
{
	class Actor;

	class Component : public Core
	{
	protected:
		Actor* owner;

	public:
		FORCEINLINE Actor* GetOwner() const
		{
			return owner;
		}

	protected:
		Component(Actor* _owner);

	public:
		virtual ~Component() = default;

	public:
		virtual void Construct() override;
		virtual void Deconstruct() override;
		virtual void BeginPlay() override {};
		virtual void EarlyTick(const float& _deltaTime) override {};
		virtual void Tick(const float& _deltaTime) override {};
		virtual void LateTick(const float& _deltaTime) override {};
		virtual void BeginDestroy() override {};

		virtual std::string ToString() const override;
	};


}

