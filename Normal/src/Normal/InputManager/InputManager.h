#pragma once

#include "Normal/Core/Core.h"

namespace Normal {

	class Event;

	// https://nerdooit.github.io/2020/06/17/design_pattern_sigleton_2.html
	template<typename T> 
	class NORMAL_API InputManager
	{
	public:
		virtual void OnEvent( Event& event ) = 0;

	protected:
		InputManager( )
		{
			// Empty 
		}

	protected:
		InputManager( const InputManager& ) = delete;
		void operator=( const InputManager& ) = delete;

	public:
		inline static T& GetInstance()
		{
			static T instance;
			return instance;
		}
	};

} // namespace Normal