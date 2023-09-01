#include "Timer.h"
#include "Nrpch.h"
#include <GLFW/glfw3.h>

namespace Normal
{
	Timer::Timer( double seconds )
		: m_Start ( seconds ), m_End( seconds ), m_ElapsedTime( seconds )
	{ 
		// seconds�� 0.0�� ��, glfwGetTime���� ���� �ð��� ���߱� ����.
		// glfwGetTime�� glfwVSync ����� ������ �޴´�.
		if ( seconds == 0.0f )
		{
			m_Start = glfwGetTime();
			m_End = m_Start;
			m_ElapsedTime = m_Start;
		}
	}

	void Timer::Reset( double seconds )
	{
		m_Start = seconds;
		m_End = seconds;
		m_ElapsedTime = seconds;
	}

	void Timer::Update()
	{
		m_End = glfwGetTime();
		m_ElapsedTime = m_End - m_Start;
		m_Start = m_End;
	}
}