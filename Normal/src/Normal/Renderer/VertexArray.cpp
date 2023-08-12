#include "Nrpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Buffer.h"

#include <Platform/OpenGL/OpenGLVertexArray.h>

namespace Normal {

	VertexArray* VertexArray::Create()
	{
		switch ( Renderer::GetGraphicAPI() )
		{
			case RendererAPI::API::OpenGL: return new OpenGLVertexArray();
			case RendererAPI::API::Vulkan:
			case RendererAPI::API::DirectX11:
			case RendererAPI::API::DirectX12:
			NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
		}

		NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Vertex Buffer!" );
		return nullptr;
	}

}  // namespace Normal