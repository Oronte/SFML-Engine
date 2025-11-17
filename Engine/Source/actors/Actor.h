#pragma once
#include "Core.h"
#include "components/Component.h"

namespace engine
{
	class Transform;

	class Actor : public Core
	{
	protected:
		std::unique_ptr<Transform> transform;
		std::unordered_map<std::type_index, std::unique_ptr<Component>> components;

	public:
		FORCEINLINE Transform* GetTransform()
		{
			return transform.get();
		}

		Actor();

	protected:
		template <typename Type, typename ...Args, IS_BASE_OF(Component, Type)>
		FORCEINLINE Type* CreateComponent(Args&&... _args)
		{
			Type* _component = new Type(this, forward<Args>(_args)...);
			return _component;
		}

	public:
		virtual void SetActive(const bool& _status) override;
		void Construct() override;
		void Deconstruct() override;
		void BeginPlay() override;
		void EarlyTick(const float& _deltaTime) override;
		void Tick(const float& _deltaTime) override;
		void LateTick(const float& _deltaTime) override;
		void BeginDestroy() override;
	};

}



