#pragma once
#include "CoreMinimal.h"

namespace engine
{
	class Timer
	{
		bool isToDelete;
		bool isRunning;
		bool isLoop;
		float currentTime;
		float duration;
		std::function<void()> callback;

	public:
		FORCEINLINE void SetDuration(const float& _duration)
		{
			duration = _duration;
		}
		FORCEINLINE bool IsToDelete() const
		{
			return isToDelete;
		}
		FORCEINLINE bool IsRunning() const
		{
			return isRunning;
		}
		FORCEINLINE bool IsLoop() const
		{
			return isLoop;
		}
		FORCEINLINE float GetCurrentTime() const
		{
			return currentTime;
		}

	public:
		Timer(const std::function<void()>& _callback, const float& _duration, const bool _startRunning = false,
			const bool _isLoop = false);

	public:
		void Start();
		void Update(const float& _deltaTime);
		void Stop();
		void Resume();
		void Reset();
		void Pause();
	};

}

/////////////////////////////////////////////////////////////
// 
// 
// 
/////////////////////////////////////////////////////////////