#include "Timer.h"
#include "Nrpch.h"
#include <GLFW/glfw3.h>

namespace Normal
{
	Timer::Timer( double seconds )
		: m_Start ( seconds ), m_End( seconds ), m_ElapsedTime( seconds )
	{ 
		// seconds가 0.0일 때, glfwGetTime으로 기준 시간을 맞추기 위함.
		// glfwGetTime은 glfwVSync 기능의 영향을 받는다.
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