#pragma once

#include "Core.h"

namespace Normal {

	class NORMAL_API Timer
	{
	public:
	    inline static struct s_Seconds	    {} Seconds;
		inline static struct s_Milliseconds {} Milliseconds;

	public:
		explicit Timer( double seconds = 0.0 );
		~Timer() = default;

	public:
		void Reset( double seconds = 0.0 );
		void Update();

	public:
		inline float DeltaTime( const s_Seconds& ) const { return static_cast<float>(m_ElapsedTime); }
		inline float DeltaTime( const s_Milliseconds& ) const { return static_cast<float>( m_ElapsedTime * 1000.0 ); }

	private:
		double	m_Start;
		double	m_End;
		double	m_ElapsedTime;

	};
} // namespace Normal