#include "Nrpch.h"
#include "Buffer.h"

#include "Renderer.h"

// TODO: ���߿� API �߰� ��, #include�� ����ȭ�ϱ�. (����ϴ� API�� �°� include �ǵ���)
#include <Platform/OpenGL/OpenGLBuffer.h>

namespace Normal {

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