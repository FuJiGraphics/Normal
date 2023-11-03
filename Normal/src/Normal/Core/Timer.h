#pragma once

#include "Core.h"

namespace Normal {

	struct NORMAL_API TimeStep
	{
		NRchar		Name[50];
		NRfloat		DeltaTime;
		NRfloat		Frame;
	};

	class NORMAL_API Timer
	{
	public:
	    inline static struct s_Seconds	    {} Seconds;
		inline static struct s_Milliseconds {} Milliseconds;
		inline static struct s_Microseconds {} Microseconds;

	public:
		explicit Timer( const char* name, double seconds = 0.0 );
		explicit Timer( const Timer& ) = delete;
		~Timer() = default;

	public:
		void Reset();
		void Update( bool DeltaMode = false );

		void Start();
		void End();

		void SetTimeStep( TimeStep* timestep );

	public:
		inline float DeltaTime( const s_Seconds& ) const { return static_cast<float>( m_DeltaTime ); }
		inline float DeltaTime( const s_Milliseconds& ) const { return static_cast<float>( m_DeltaTime * 1000.0 ); }
		inline float DeltaTime( const s_Microseconds& ) const { return static_cast<float>( m_DeltaTime * 1000000.0 ); }

		inline float ElapsedTime( const s_Seconds& ) const { return static_cast<float>( m_ElapsedTime ); }
		inline float ElapsedTime( const s_Milliseconds& ) const { return static_cast<float>( m_ElapsedTime * 1000.0 ); }
		inline float ElapsedTime( const s_Microseconds& ) const { return static_cast<float>( m_ElapsedTime * 1000000.0 ); }
		inline const char* TimerName() const { return m_TimerName; }

	private:
		NRbool		m_RecordStart;
		NRfloat		m_Frame;
		NRdouble	m_FrameStart;

		NRdouble	m_Start;
		NRdouble	m_End;
		NRdouble	m_ElapsedTime;
		NRdouble	m_DeltaTime;

		TimeStep*	m_TimeStepCallback;
		NRchar		m_TimerName[50];
	};
} // namespace Normal