#pragma once
#include "Core.h"

namespace engine
{
	class Transform;

	class Component : public Core
	{
	protected:
		class Actor* owner;

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
		virtual void Tick(const float& _deltaTime) override {};
		virtual void BeginDestroy() override {};

		virtual std::string ToString() const override;
	};


}

