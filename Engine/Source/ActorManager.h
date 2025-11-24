#pragma once
#include "actors/Actor.h"

namespace engine
{

	class ActorManager
	{
		std::vector<Actor*> actors;
		//std::vector<Actor*> garbage; //TODO multithread

	public:
		INLINE std::vector<Actor*> GetActors() const noexcept
		{
			return actors;
		}
		INLINE void AddActor(Actor* _actor)
		{
			actors.push_back(_actor);
		}
		INLINE void RemoveActor(Actor* _actor)
		{
			actors.erase(std::remove(actors.begin(), actors.end(), _actor), actors.end());
		}

		ActorManager() {}

	public:
		void BeginPlay();
		void Update(const float& _deltaTime);
		void BeginDestroy();
	};

}