#pragma once

#include <vector>
#include "Core.h"

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
		void PushModule();
		void PushOverlay();

		void PopModule();
		void PopOverlay();

		inline int size() const { return m_Container.size(); }

		inline std::vector<Level*>::iterator begin() { return m_Container.begin(); };
		inline std::vector<Level*>::iterator end() { return m_Container.end(); };

	private:
		std::vector<Level*> m_Container;
		// std::vector<Module*>::iterator m_Iterator;
	};



} // namespace Normal