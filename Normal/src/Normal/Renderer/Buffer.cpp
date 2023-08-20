#include "Nrpch.h"
#include "Buffer.h"

#include "Renderer.h"

// TODO: 나중에 API 추가 시, #include문 최적화하기. (사용하는 API에 맞게 include 되도록)
#include <Platform/OpenGL/OpenGLBuffer.h>

namespace Normal {

	int LayoutElement::ShaderDataTypeSize( const ShaderDataType& type )
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


	int LayoutElement::GetCount() const
	{
		switch ( Type )
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

	/*___________________________________________________________________________________
	 *   Vertex Buffer
	 *__________________________________________________________________________________*/
	VertexBuffer* VertexBuffer::Create( float* vertices, NRuint size )
	{
		switch ( Renderer::GetGraphicAPI() )
		{
			case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer( vertices, size );
			case RendererAPI::API::Vulkan:
			case RendererAPI::API::DirectX11:
			case RendererAPI::API::DirectX12:
				NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
		}

		NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Vertex Buffer!" );
		return nullptr;
	}

	/*___________________________________________________________________________________
	 *   Index Buffer
	 *__________________________________________________________________________________*/
	IndexBuffer* IndexBuffer::Create( NRuint* indices, NRuint count )
	{
		switch ( Renderer::GetGraphicAPI() )
		{
			case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer( indices, count );
			case RendererAPI::API::Vulkan:
			case RendererAPI::API::DirectX11:
			case RendererAPI::API::DirectX12:
				NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
		}

		NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Index Buffer!" );
		return nullptr;
	}

} // namespace Normal