#pragma once

#include "Core.h"

#include <vector>

namespace Normal {

	class Level;

	class NORMAL_API LevelContainer
	{
	public:
		LevelContainer();
		~LevelContainer();
		LevelContainer( LevelContainer& ) = delete;
		void operator= ( LevelContainer& ) = delete;

	public:
		// TODO : 레벨 컨테이너 구현하고 만들기 
		// 1. 레벨의 정방향 순서 
		// 2. 오버레이는 항상 레이어 마지막에
		// 3. 이벤트가 발생되는 시점을 고려할 것 
		void PushLevel( Level* level );
		void PushOverlay();
		void PopLevel();
		void PopOverlay();

	public:
		using container = std::vector< Level* >;

		inline int size() const { return m_Container.size(); }
		inline container::iterator begin() { return m_Container.begin(); };
		inline container::iterator end() { return m_Container.end(); };

	private:
		container m_Container;
		container::iterator m_InsertLevel;
	};



} // namespace Normal