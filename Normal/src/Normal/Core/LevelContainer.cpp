#include "Nrpch.h"

#include "Level.h"
#include "LevelContainer.h"

namespace Normal {

	LevelContainer::LevelContainer()
		: m_Container()
		, m_InsertLevel()
	{
		NR_CORE_INFO( "[{0}] Successfully deallocate memory.", NR_GET_NAME );
		m_InsertLevel = m_Container.begin();
	}

	LevelContainer::~LevelContainer()
	{
		if ( m_Container.size() )
		{
			for ( const auto& level : m_Container )
			{
				NR_CORE_ASSERT( level, "Unexpected Error : Failed to deallocate memory.");
				// delete level;
			}
		}
		NR_CORE_INFO( "[{0}] Successfully deallocate Memory.", NR_GET_NAME );
	}

	void LevelContainer::PushLevel( Level* pLevel )
	{
		NR_CORE_ASSERT( pLevel, "Unexpected Error : Failed to called a emplace" );
		m_InsertLevel = m_Container.emplace( m_InsertLevel, pLevel );
	}

	void LevelContainer::PushOverlay( Level* pOverlay )
	{
		NR_CORE_ASSERT( pOverlay, "Unexpected Error : Failed to called a emplace_back" );
		m_Container.emplace_back( pOverlay );
		m_InsertLevel = m_Container.begin();
	}

	void LevelContainer::PopLevel( Level* pLevel )
	{
		NR_CORE_ASSERT( pLevel, "Unexpected Error : Failed to called a PopLevel" );
		auto data = std::find_if( m_Container.begin(), m_Container.end(),
								  [&pLevel]( const std::unique_ptr<Level>& pTarget )
								  {
									  return pTarget.get() == pLevel;
								  } );
		m_InsertLevel = m_Container.begin();
		if ( data != m_Container.end() )
		{
			m_Container.erase( data );
		}
	}

	void LevelContainer::PopOverlay( Level* pOverlay )
	{
		NR_CORE_ASSERT( pOverlay, "Unexpected Error : Failed to called a PopOverlay" );
		auto data = std::find_if( m_Container.begin(), m_Container.end(),
								  [&pOverlay]( const std::unique_ptr<Level>& pTarget )
								  {
									  return pTarget.get() == pOverlay;
								  } );
		m_InsertLevel = m_Container.begin();
		if ( data != m_Container.end() )
		{
			m_Container.erase( data );
		}
	}


} // namespace Normal