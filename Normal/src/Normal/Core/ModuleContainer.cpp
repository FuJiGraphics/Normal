#include "Nrpch.h"
#include "ModuleContainer.h"

#include "Module.h"

namespace Normal {


	void ModuleContainer::push_back( Module& module )
	{
		m_Modules.push_back( &module );
	}

	bool ModuleContainer::erase( std::string moduleName )
	{
		size_t indexCount = 0;
		auto end = m_Modules.end();
		for ( auto iter = m_Modules.begin(); iter != end; ++iter )
		{
			const std::string& name = ( *iter )->GetModuleName();
			if ( name == moduleName )
			{
				m_Modules.erase( iter );
				return true;
			}
		}
		return false;
	}


} // namespace Normal