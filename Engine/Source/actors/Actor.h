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
			std::type_index _type = typeid(Type);
			if (components.contains(_type))
			{
				LOG(VerbosityType::Warning, "There is already component of this type");
				return nullptr;
			}

			std::unique_ptr<Type> _component = std::make_unique<Type>(this, forward<Args>(_args)...);
			components.emplace(_type, std::move(_component));
			return _component.get();
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



