#include "Nrpch.h"
#include "Buffer.h"

#include "Renderer.h"

// TODO: 나중에 API 추가 시, #include문 최적화하기. (사용하는 API에 맞게 include 되도록)
#include <Platform/OpenGL/OpenGLBuffer.h>

namespace Normal {

	/*___________________________________________________________________________________
	 *   Vertex Buffer
	 *__________________________________________________________________________________*/
	VertexBuffer* VertexBuffer::Create( float* vertices, NRuint size )
	{
		const GraphicAPI& renderAPI = Renderer::GetGraphicAPI();
		switch ( renderAPI )
		{
			case GraphicAPI::OpenGL: return new OpenGLVertexBuffer( vertices, size );
			case GraphicAPI::Vulkan:
			case GraphicAPI::DirectX11:
			case GraphicAPI::DirectX12:
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
		const GraphicAPI& renderAPI = Renderer::GetGraphicAPI();
		switch ( renderAPI )
		{
			case GraphicAPI::OpenGL: return new OpenGLIndexBuffer( indices, count );
			case GraphicAPI::Vulkan:
			case GraphicAPI::DirectX11:
			case GraphicAPI::DirectX12:
				NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
		}

		NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Index Buffer!" );
		return nullptr;
	}

} // namespace Normal