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
		inline static T& GetInstance()
		{
			static T instance;
			return instance;
		}

	protected:
		InputManager( ) { }
		virtual ~InputManager() { }

	protected:
		InputManager( const InputManager& ) = delete;
		void operator=( const InputManager& ) = delete;

		NR_SET_NAME( "InputManager" );
	};

} // namespace Normal