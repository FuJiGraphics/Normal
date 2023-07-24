#include "Nrpch.h"

#include "Level.h"
#include "LevelContainer.h"

namespace Normal {
	LevelContainer::LevelContainer()
		: m_Container()
		, m_InsertLevel()
	{
		m_InsertLevel = m_Container.begin();
	}

	LevelContainer::~LevelContainer()
	{
		if ( m_Container.size() )
		{
			for ( auto level : m_Container )
			{
				NR_CORE_ASSERT( !level, "Unexpected Error : Failed to deallocate memory." );
				delete level;
			}
		}
		NR_CORE_TRACE( "Successfully deallocate memory." );
	}

	void LevelContainer::PushLevel( Level* level )
	{
		m_Container.insert( m_InsertLevel, level );
	}

	void LevelContainer::PushOverlay()
	{

	}

	void LevelContainer::PopLevel()
	{

	}

	void LevelContainer::PopOverlay()
	{

	}


} // namespace Normal