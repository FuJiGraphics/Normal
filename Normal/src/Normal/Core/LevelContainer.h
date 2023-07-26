#pragma once

#include "Core.h"

#include <vector>

namespace Normal {

	class Level;

	class NORMAL_API LevelContainer
	{
	public:
		LevelContainer();
		virtual ~LevelContainer();

	private:
		LevelContainer( LevelContainer& ) = delete;
		void operator= ( LevelContainer& ) = delete;

	public:
		void PushLevel( Level* pLevel );
		void PushOverlay( Level* pOverlay );
		void PopLevel( Level* pLevel );
		void PopOverlay( Level* pOverlay );

	public:
		using container = std::vector< std::unique_ptr<Level> >;

		inline bool empty() const { return m_Container.empty(); }
		container::iterator begin() { return m_Container.begin(); }
		container::iterator end() { return m_Container.end(); }

	private:
		container m_Container;
		container::iterator m_InsertLevel;

		NR_SET_NAME( "LevelContainer" );
	};



} // namespace Normal