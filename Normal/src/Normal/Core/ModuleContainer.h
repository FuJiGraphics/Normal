#pragma once

#include <vector>
#include "Core.h"

namespace Normal {

	class Module;

	class NORMAL_API ModuleContainer
	{
	public:
		ModuleContainer();
		ModuleContainer( ModuleContainer& ) = delete;
		void operator= ( ModuleContainer& ) = delete;

	public:
		void push_back( Module& module );
		bool erase( std::string moduleName );

		inline int size() const { return m_Modules.size(); }

		inline std::vector<Module*>::iterator begin() { return m_Modules.begin(); };
		inline std::vector<Module*>::iterator end() { return m_Modules.end(); };

	private:
		std::vector<Module*> m_Modules;
		// std::vector<Module*>::iterator m_Iterator;
	};



} // namespace Normal