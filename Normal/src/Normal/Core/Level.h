#pragma once

#include "Core.h"
#include "Normal/Events/Event.h"

namespace Normal {

	class NORMAL_API Level
	{
	public:
		Level( const std::string& levelName )
			: m_LevelName( levelName )
		{
			// Empty
		}
		
		virtual void OnEvent( Event& event ) {};

		virtual std::string GetName() const { return m_LevelName; }
	private:
		std::string m_LevelName;
	};



} // namespace Normal