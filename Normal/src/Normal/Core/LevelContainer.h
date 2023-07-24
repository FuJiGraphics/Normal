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
		// TODO : ���� �����̳� �����ϰ� ����� 
		// 1. ������ ������ ���� 
		// 2. �������̴� �׻� ���̾� ��������
		// 3. �̺�Ʈ�� �߻��Ǵ� ������ ����� �� 
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