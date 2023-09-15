#pragma once

#include "Core.h"


namespace Normal
{
	namespace Core {
		struct NORMAL_API NrMakePtr
		{
		public:
			NrMakePtr( void* src, size_t size = 1 )
				: Ptr( src ), Size( size )
			{ }
			~NrMakePtr()
			{
				if ( Size > 0 && Ptr != nullptr )
				{
					DestroyPtr();
				}
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
			void* Ptr = nullptr;
			size_t	Size = 0;
		};
	} // namespace Core

	template <typename T>
	class NORMAL_API NrPtr
	{
	public:

		explicit NrPtr() = default;
		explicit NrPtr( Core::NrMakePtr&& p )
			: m_OwnerPtr( nullptr )
		{
			if ( p.Ptr != m_Ptr )
			{
				m_Ptr = reinterpret_cast<T*>( p.Ptr );
				m_Size = p.Size;
				m_OwnerPtr = this;
				p.Size = 0;
				p.ClearPtr();
				++m_SharedCount;
			}
			else
				p.DestroyPtr();
		}
		NrPtr( NrPtr<T>& ref )
		{
			m_Size = ref.GetSize();
			m_Ptr = ref.GetPtr();
			m_OwnerPtr = ref.GetOwner();
			ref.IncSharedConut();
		}
		virtual ~NrPtr()
		{
			--m_SharedCount;
			if ( m_OwnerPtr == this && m_Ptr != nullptr )
			{
				( m_Size <= 1 ) ? delete m_Ptr : delete[] m_Ptr;
				m_Ptr = nullptr;
			}
		}

	public:
		static inline Core::NrMakePtr MakePtr( T* ptr, size_t size = 1 )
		{
			return { ptr, size };
		}
		static inline Core::NrMakePtr MakePtr( size_t size = 1 )
		{
			T* ptr = ( size == 1 ) ? new T : new T[size];
			return { ptr, size };
		}
		inline T& operator *() const { return *m_Ptr; }
		inline T* operator->() const { return m_Ptr; }
		inline NrPtr<T>& operator =( Core::NrMakePtr&& p )
		{
			if ( m_OwnerPtr != this && p.Ptr != m_Ptr )
			{
				m_Ptr = reinterpret_cast<T*>( p.Ptr );
				m_Size = p.Size;
				if ( m_OwnerPtr != nullptr )
					m_OwnerPtr->DecSharedCount();
				m_OwnerPtr = this;
				m_SharedCount++;
				p.Size = 0;
				p.ClearPtr();
			}
			else
				p.DestroyPtr();
			return ( *this );
		}

		inline NrPtr<T>& operator =( NrPtr<T>& p )
		{
			m_Ptr = p.GetPtr();
			m_Size = p.GetSize();
			if ( m_OwnerPtr != nullptr )
				m_OwnerPtr->DecSharedCount();
			m_OwnerPtr = p.GetOwner();
			p.IncSharedConut();
			return *this;
		}

		inline const bool IsOwner() const { return ( m_OwnerPtr == this ) ? true : false; }
		inline void	IncSharedConut() { if ( m_OwnerPtr == this ) ++m_SharedCount; }
		inline void DecSharedCount() { if ( m_OwnerPtr == this ) --m_SharedCount; }

		inline T* GetPtr() const { return m_Ptr; }
		inline size_t GetSize() const { return m_Size; }
		inline NrPtr<T>* GetOwner() const { return m_OwnerPtr; }
		inline size_t GetSharedCount() const { return m_OwnerPtr->m_SharedCount; }

	private:
		T* m_Ptr = nullptr;
		size_t			m_Size = 0;
		NrPtr<T>* m_OwnerPtr = nullptr;
		unsigned int	m_SharedCount = 0;
	};

} // namespace Normal
