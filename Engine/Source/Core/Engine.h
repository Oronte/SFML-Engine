#pragma once
#include "GameFramework/Level.h"

namespace engine
{

	class Engine
	{
	public:
		Event<> onEngineStart;
		Event<> onEngineStop;

	private:
		Level* level = nullptr;
		
	public:
		Engine(Level* _level);

		void Start();
		void Update();
		void Stop();
	};

}

