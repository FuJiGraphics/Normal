#pragma once

#include "Core.h"

#include <vector>

namespace Normal {

	class Level;

	class NORMAL_API LevelContainer
	{
		using iter = std::vector<Level*>::iterator;

	public:
		explicit LevelContainer();
		virtual ~LevelContainer();

	private:
		LevelContainer( LevelContainer& ) = delete;
		void operator= ( LevelContainer& ) = delete;

	public:
		bool InsertLevel( Level* pLevel );
		bool InsertOverlay( Level* pOverlay );
		bool RemoveLevel( Level* pLevel );
		bool RemoveOverlay( Level* pOverlay );

	protected:
		iter FindLevel( Level* pLevel );

	public:
		inline bool empty() const { return m_Container.empty(); }
		iter begin() { return m_Container.begin(); }
		iter end() { return m_Container.end(); }

	private:
		std::vector<Level*> m_Container;
		NRuint64 m_InsertIndex;

		NR_SET_NAME( "LevelContainer" );
	};



} // namespace Normal