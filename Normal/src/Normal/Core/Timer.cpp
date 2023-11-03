#include "Timer.h"
#include "Nrpch.h"
#include <GLFW/glfw3.h>

namespace Normal
{
	Timer::Timer( const char* name, double seconds )
		: m_Frame( 0.0f ), m_FrameStart( 0.0 ), m_RecordStart( true )
		, m_Start ( seconds ), m_End( seconds ), m_ElapsedTime( seconds )
		, m_TimeStepCallback( nullptr )
	{ 
		// seconds가 0.0일 때, glfwGetTime으로 기준 시간을 맞추기 위함.
		// glfwGetTime은 glfwVSync 기능의 영향을 받는다.
		strncpy( m_TimerName, name, strlen( name ) + 1 );
		strcat( m_TimerName, "\0" );
		if ( seconds == 0.0f )
		{
			m_Start = glfwGetTime();
			m_End = m_Start;
			m_ElapsedTime = m_Start;
			m_DeltaTime = m_Start;
		}
	}

	void Timer::Reset()
	{
		m_Start = glfwGetTime();
		m_End = m_Start;
		m_ElapsedTime = m_Start;
		m_DeltaTime = m_Start;
	}

	void Timer::Update( bool DeltaMode )
	{
		m_End = glfwGetTime();
		m_ElapsedTime = m_End - m_Start;
		if ( DeltaMode )
			m_Start = m_End;
		if ( m_TimeStepCallback != nullptr )
		{
			m_TimeStepCallback->DeltaTime = m_ElapsedTime;
			m_TimeStepCallback->Frame = m_Frame;
		}
	}

	void Timer::Start()
	{
		m_Start = glfwGetTime();
		if ( m_RecordStart )
		{
			m_RecordStart = false;
			m_FrameStart = m_Start;
		}
	}

	void Timer::End()
	{
		m_End = glfwGetTime();
		m_DeltaTime = m_End - m_Start;
		if ( m_TimeStepCallback != nullptr )
		{
			m_TimeStepCallback->DeltaTime = DeltaTime( Timer::Milliseconds );
			if ( m_End - m_FrameStart >= 1.0001f )
			{
				m_TimeStepCallback->Frame = m_Frame;
				m_Frame = 0.0f;
				m_RecordStart = true;
			}
		}
		++m_Frame;
	}

	void Timer::SetTimeStep( TimeStep* timestep )
	{
		m_TimeStepCallback = timestep;
		strcpy( timestep->Name, m_TimerName );
		strcat( timestep->Name, "\0" );
	}
} // namespace Normal