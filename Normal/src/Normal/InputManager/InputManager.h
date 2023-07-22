#pragma once

#include "Normal/Core/Core.h"

#include "Normal/Core/Module.h"

namespace Normal {

	// https://nerdooit.github.io/2020/06/17/design_pattern_sigleton_2.html
	template<typename T> 
	class NORMAL_API InputManager : public Module
	{
	protected:
		InputManager( const std::string& moduleName )
			: Module( moduleName )
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