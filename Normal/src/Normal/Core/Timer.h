#pragma once

#include <Normal/Core/Core.h>
#include <chrono>

namespace Normal {

#define NR_DURATION_CAST(x, args) std::chrono::duration_cast<std::chrono::##args>( x ).count();

	class NORMAL_API Timer
	{
	protected:
		using StedyTimePoint = std::chrono::steady_clock::time_point;

	public:
		const inline static struct T_Hours    {}  Hours;
		const inline static struct T_Minutes  {}  Minutes;
		const inline static struct T_Seconds  {}  Seconds;
		const inline static struct T_Millisec {}  Milliseconds;
		const inline static struct T_Microsec {}  Microseconds;
		const inline static struct T_Nanosec  {}  Nanoseconds;

	public:
		explicit Timer() = default;
		~Timer() = default;

	public:
		inline void Start() { m_PrevTime = m_CurrTime; m_Start = std::chrono::steady_clock::now(); }
		inline void End()   { m_End = std::chrono::steady_clock::now(); m_CurrTime = m_End - m_Start; }

		inline decltype( auto ) ElapsedTime( const T_Hours& type )    const { return NR_DURATION_CAST( m_CurrTime, hours ) }
		inline decltype( auto ) ElapsedTime( const T_Minutes& type )  const { return NR_DURATION_CAST( m_CurrTime, minutes ) }
		inline decltype( auto ) ElapsedTime( const T_Seconds& type )  const { return NR_DURATION_CAST( m_CurrTime, seconds ) }
		inline decltype( auto ) ElapsedTime( const T_Millisec& type ) const { return NR_DURATION_CAST( m_CurrTime, milliseconds ) }
		inline decltype( auto ) ElapsedTime( const T_Microsec& type ) const { return NR_DURATION_CAST( m_CurrTime, microseconds ) }
		inline decltype( auto ) ElapsedTime( const T_Nanosec& type )  const { return NR_DURATION_CAST( m_CurrTime, nanoseconds ) }
		
	private:
		StedyTimePoint m_Start;
		StedyTimePoint m_End;

		std::chrono::nanoseconds m_PrevTime = std::chrono::nanoseconds::zero();
		std::chrono::nanoseconds m_CurrTime = std::chrono::nanoseconds::zero();
	};
}