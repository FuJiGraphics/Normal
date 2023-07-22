#pragma once

#include "Core.h"
#include "Normal/Events/Event.h"

namespace Normal {

	class NORMAL_API Module
	{
	public:
		Module( const std::string& moduleName )
			: m_ModuleName( moduleName )
		{
			// Empty
		}

		virtual void OnEvent( Event& event ) {};

		virtual std::string GetModuleName() const { return m_ModuleName; }
	private:
		std::string m_ModuleName;
	};



} // namespace Normal