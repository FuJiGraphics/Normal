#pragma once

#include <Normal/Core/Core.h>
#include <iostream>
#include <vector>
#include <string>

namespace Normal {

	enum class ShaderDataType {
		None = 0,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
		Int, Int2, Int3, Int4,
		Bool,
	};


	/*___________________________________________________________________________________
	 *   Layout Element
	 *__________________________________________________________________________________*/
	struct NORMAL_API LayoutElement
	{
		ShaderDataType Type;   // Data type used in the shader
		std::string Name;      // Data name
		NRbool Normalized;     // Enable Normalize Option
		NRuint DataSize;       // Size of Datum
		NRuint Offset;         // Begin attribute pointer

		LayoutElement( ShaderDataType&& type, std::string&& name, NRbool normalized = false )
			: Type( std::move( type ) )
			, Name( std::move( name ) )
			, Normalized( normalized )
			, DataSize( ShaderDataTypeSize( type ) )
			, Offset( 0 )
		{ } 

		static int ShaderDataTypeSize( const ShaderDataType& type );
		int GetCount() const;
	};


	/*___________________________________________________________________________________
	 *   Buffer Layout
	 *__________________________________________________________________________________*/
	class NORMAL_API BufferLayout
	{
		using LayoutElements = std::vector<LayoutElement>;
	public:
		explicit BufferLayout() = default;
	    BufferLayout( const std::initializer_list<LayoutElement>& elements )
			: m_Elements( elements )
			, m_Stride( 0 )
		{
			CalculateOffsetAndStride();
		}

		inline NRuint GetStride() const { return m_Stride; }
		inline NRuint GetElementsSize() const { return m_Elements.size(); }

		inline LayoutElements::iterator begin() { return m_Elements.begin(); }
		inline LayoutElements::iterator end() { return m_Elements.end(); }

		inline LayoutElements::const_iterator begin() const { return m_Elements.begin(); }
		inline LayoutElements::const_iterator end() const { return m_Elements.end(); }

	private: 
		void CalculateOffsetAndStride()
		{
			NRuint offset = 0;
			m_Stride = 0;
			for ( auto& element : m_Elements )
			{
				element.Offset = offset;
				offset += element.DataSize;
				m_Stride += element.DataSize;
			}
		}

	private:
		std::vector<LayoutElement> m_Elements;
		NRuint m_Stride; 
	};


	/*___________________________________________________________________________________
	 *   Vertex Buffer
	 *__________________________________________________________________________________*/
	class NORMAL_API VertexBuffer
	{
	protected:
		explicit VertexBuffer() = default;
	public:
		virtual ~VertexBuffer() = default;

	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetLayout( const BufferLayout& layout ) = 0;
		virtual const BufferLayout& GetLayout() const = 0;

	public:
		static VertexBuffer* Create( float* vertices, NRuint size );

	};



	/*___________________________________________________________________________________
	 *   Index Buffer
	 *__________________________________________________________________________________*/
	class NORMAL_API IndexBuffer
	{
	protected:
		explicit IndexBuffer() = default;
	public:
		virtual ~IndexBuffer() = default;

	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual NRuint GetIndexCount() const = 0;

	public:
		static IndexBuffer* Create( NRuint* indices, NRuint count );
	};


} // namespace Normal