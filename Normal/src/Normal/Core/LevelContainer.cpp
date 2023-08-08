#include "Nrpch.h"
#include "Level.h"
#include "LevelContainer.h"

namespace Normal {

	LevelContainer::LevelContainer()
		: m_Container()
		, m_InsertIndex( 0 )
	{
		NR_CORE_INFO_CTOR;
	}

	LevelContainer::~LevelContainer()
	{
		if ( m_Container.size() )
		{
			for ( const auto& level : m_Container )
			{
				NR_CORE_ASSERT( level, "Unexpected Error : Failed to deallocate memory.");
				delete level;
			}
		}
		NR_CORE_INFO_DTOR;
	}

	bool LevelContainer::InsertLevel( Level* pLevel )
	{
		NR_CORE_ASSERT( pLevel, "Unexpected Error : Failed to called a emplace" );

		auto findLevel = FindLevel( pLevel );
		if ( findLevel == m_Container.end() )
		{
			m_Container.emplace( m_Container.begin() + m_InsertIndex, pLevel );
			++m_InsertIndex;
			return true;
		}
		return false;
	}

	bool LevelContainer::InsertOverlay( Level* pOverlay )
	{
		NR_CORE_ASSERT( pOverlay, "Unexpected Error : Failed to called a emplace_back" );
		
		auto findOverlay = FindLevel( pOverlay );
		if ( findOverlay == m_Container.end() )
		{
			m_Container.emplace_back( pOverlay );
			return true;
		}
		return false;
	}

	bool LevelContainer::RemoveLevel( Level* pLevel )
	{
		NR_CORE_ASSERT( pLevel, "Unexpected Error : Failed to called a PopLevel" );
		
		auto findLevel = FindLevel( pLevel );
		if ( findLevel != m_Container.end() )
		{
			m_Container.erase( findLevel );
			--m_InsertIndex;
			return true;
		}
		return false;
	}

	bool LevelContainer::RemoveOverlay( Level* pOverlay )
	{
		NR_CORE_ASSERT( pOverlay, "Unexpected Error : Failed to called a PopOverlay" );
		
		auto findOverlay = FindLevel( pOverlay );
		if ( findOverlay != m_Container.end() )
		{
			m_Container.erase( findOverlay );
			return true;
		}
		return false;
	}

	LevelContainer::iter LevelContainer::FindLevel( Level* pLevel )
	{
		return std::find_if( m_Container.begin(), m_Container.end(),
							[pLevel]( Level* pTarget )
							{
								return pLevel == pTarget;
							} );
	} // auto LevelContainer::FindLevel( Level* pLevel )


} // namespace Normal