#pragma once

#include <Normal/Core/Core.h>
#include <iostream>
#include <vector>
#include <string>

namespace Normal {

	// These classes just only surve interface functionalities.

	enum class ShaderDataType {
		None = 0,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
		Int, Int2, Int3, Int4,
		Bool,
	};

	static int ShaderDataTypeSize( const ShaderDataType& type )
	{
		switch ( type )
		{
			case ShaderDataType::Float:   return 4;
			case ShaderDataType::Float2:  return 4 * 2;
			case ShaderDataType::Float3:  return 4 * 3;
			case ShaderDataType::Float4:  return 4 * 4;
			case ShaderDataType::Mat3:    return 3 * 4 * 3;
			case ShaderDataType::Mat4:    return 4 * 4 * 4;
			case ShaderDataType::Int:     return 4;
			case ShaderDataType::Int2:    return 4 * 2;
			case ShaderDataType::Int3:    return 4 * 3;
			case ShaderDataType::Int4:    return 4 * 4;
			case ShaderDataType::Bool:    return 1;
		}

		NR_CORE_ASSERT( nullptr, "Unexpected Error: Unknown ShaderDataType." );
		return 0;
	}
	
	static int CountShaderTypeElements( const ShaderDataType& type )
	{
		switch ( type )
		{
			case ShaderDataType::Float:   return 1;
			case ShaderDataType::Float2:  return 2;
			case ShaderDataType::Float3:  return 3;
			case ShaderDataType::Float4:  return 4;
			case ShaderDataType::Mat3:    return 3 * 3;
			case ShaderDataType::Mat4:    return 4 * 4;
			case ShaderDataType::Int:     return 1;
			case ShaderDataType::Int2:    return 2;
			case ShaderDataType::Int3:    return 3;
			case ShaderDataType::Int4:    return 4;
			case ShaderDataType::Bool:    return 1;
		}

		NR_CORE_ASSERT( nullptr, "Unexpected Error: Unknown ShaderDataType." );
		return 0;
	}

	struct NORMAL_API LayoutElement
	{
		ShaderDataType Type;   // Data type used in the shader
		std::string Name;      // Data name
		NRbool Normalized;     // Enable Normalize Option
		NRuint DataSize;       // Size of Datum
		NRuint Offset;         // Begin attribute pointer 
		NRuint Count;          // Number of type element

		LayoutElement( ShaderDataType&& type, std::string&& name, NRbool normalized = false )
			: Type( std::move( type ) )
			, Name( std::move( name ) )
			, Normalized( normalized )
			, DataSize( ShaderDataTypeSize( type ) )
			, Offset( 0 )
			, Count( CountShaderTypeElements( type ) )
		{ } 
	};

	class NORMAL_API BufferLayout
	{
	public:
		explicit BufferLayout() = default;
	    BufferLayout( const std::initializer_list<LayoutElement>& elements )
			: m_Elements( elements )
			, m_Stride( 0 )
		{
			CalculateOffsetAndStride();
		}

		inline NRuint GetStride() const { return m_Stride; }

		inline std::vector<LayoutElement>::iterator begin() { return m_Elements.begin(); }
		inline std::vector<LayoutElement>::iterator end() { return m_Elements.end(); }

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


	class NORMAL_API VertexBuffer
	{
	protected:
		explicit VertexBuffer() = default;
	public:
		virtual ~VertexBuffer() = default;

	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetLayout( BufferLayout& layout ) = 0;
		// virtual const BufferLayout& GetLayout() const = 0;

		static VertexBuffer* Create( float* vertices, NRuint size );
	};



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

		static IndexBuffer* Create( NRuint* indices, NRuint count );
	};


} // namespace Normal