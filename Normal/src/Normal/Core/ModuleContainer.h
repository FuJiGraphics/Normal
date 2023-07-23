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
		// TODO : ���� �����̳� �����ϰ� ����� 
		// 1. ������ ������ ���� 
		// 2. �������̴� �׻� ���̾� ��������
		// 3. �̺�Ʈ�� �߻��Ǵ� ������ ����� �� 
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