#pragma once

#include "Core.h"
#include <utility> 

namespace Normal
{	
	//------------------------ NrMakePtr --------------------------------
	template <typename T>
	struct NORMAL_API NrMakePtr
	{
	public:
		NrMakePtr( T* src, size_t size = 1 )
			: Ptr( src ), Size( size )
		{ }

		~NrMakePtr()
		{
			if ( Size > 0 && Ptr != nullptr )
				DestroyPtr();
		}

		inline void ClearPtr() { Ptr = nullptr; }
		inline void DestroyPtr()
		{
			if ( Ptr != nullptr )
			{
				( Size == 1 ) ? delete Ptr : delete[] Ptr;
				Ptr = nullptr;
			}
		}

	public:
		T*			Ptr  = nullptr;
		NRuint64	Size = 0;
	};
	//-------------------------------------------------------------------


	//----------------------------NrPtr----------------------------------
	template <typename T>
	class NORMAL_API NrPtr
	{
	public:
		NrPtr() = default;

		template <typename U>
		NrPtr( const NrMakePtr<U>& src )
		{
			if ( src.Ptr != m_Ptr )
			{
				m_Ptr = src.Ptr;
				m_Size = src.Size;
				m_Head = this;
				src.Size = 0;
				src.ClearPtr();
			}
			else
				src.DestroyPtr();
		}

		NrPtr( const NrPtr<T>& src )
		{
			m_Ptr = src.GetLowPtr();
			m_Size = src.GetSize();
			m_Head = src.GetHead();
			SetLink( &src );
		}

		virtual ~NrPtr()
		{
			if ( m_Next == nullptr && m_Prev == nullptr )
			{
				( m_Size <= 1 && m_Ptr != nullptr ) ? 
					delete m_Ptr : delete[] m_Ptr;
				m_Ptr = nullptr;
			}
			SetDelLink();
		}

	public:
		inline T& operator *() const { return *m_Ptr; }
		inline T* operator->() const { return m_Ptr; }

		template <typename U>
		inline NrPtr<T>& operator =( NrMakePtr<U>&& p )
		{
			if ( p.Ptr != m_Ptr )
			{
				m_Ptr = p.Ptr;
				m_Size = p.Size;
				if ( m_Ptr != nullptr )
					SetDelLink();
				m_Head = this;
				p.Size = 0;
				p.ClearPtr();
			}
			else
				p.DestroyPtr();
			return ( *this );
		}

		inline NrPtr<T>& operator =( NrPtr<T>& p )
		{
			m_Ptr = p.GetLowPtr();
			m_Size = p.GetSize();
			m_Head = p.GetHead();
			SetLink( &p );
			return *this;
		}

		inline NrPtr<T>& operator =( const NrPtr<T>& p )
		{
			m_Ptr = p.GetLowPtr();
			m_Size = p.GetSize();
			SetLink( &p );
			return *this;
		}

		inline void	SetLink( const NrPtr<T>* src )
		{
			NrPtr<T>* target = ( NrPtr<T>* )( src );
			if ( m_Ptr != nullptr )
				SetDelLink();
			m_Prev = target;
			target->SetNext( this );
			m_Head = target->GetHead();
		}

		inline void SetDelLink()
		{
			if ( m_Next != nullptr )
				m_Next->SetPrev( m_Prev );
			if ( m_Prev != nullptr )
				m_Prev->SetNext( m_Next );
			if ( m_Head == this && m_Prev != nullptr )
				m_Prev->SetHead( m_Prev );
		}

		inline T*			GetLowPtr() const { return m_Ptr; }
		inline NRuint64		GetSize() const { return m_Size; }
		inline NrPtr<T>*	GetHead() const { return m_Head; }
		inline void			SetHead( NrPtr<T>* head ) { m_Head = head; }
		inline void			SetNext( NrPtr<T>* next ) { m_Next = next; }
		inline void			SetPrev( NrPtr<T>* prev ) { m_Prev = prev; }
		inline bool			IsHead() const { return ( m_Head == this ) ? true : false; }

	private:
		T*			m_Ptr			= nullptr;
		NRuint64	m_Size			= 0;

	private: // Auth
		mutable NrPtr<T>*	m_Head = nullptr;
		mutable NrPtr<T>*	m_Prev = nullptr;
		mutable NrPtr<T>*	m_Next = nullptr;
	};
		
	//--------------------Handle-----------------------------------------
	template<typename T, typename... Args>
	static inline NrMakePtr<T> MakePtr( Args&&... args )
	{
		return { new T( std::forward<Args>( args )... ), 1 };
	}

	template<typename T>
	static inline NrMakePtr<T> MakePtr( T* ptr, NRuint64 size = 1 )
	{
		return { ptr, size };
	}

	template<typename T>
	static inline NrMakePtr<T> MakePtr( NRuint64 size = 1 )
	{
		T* ptr = ( size <= 1 ) ? new T : new T[size];
		return { ptr, size };
	}

} // namespace Normal
