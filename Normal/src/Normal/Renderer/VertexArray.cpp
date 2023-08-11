#include "Nrpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Buffer.h"

#include <Platform/OpenGL/OpenGLVertexArray.h>

namespace Normal {

	VertexArray* VertexArray::Create()
	{
		const GraphicAPI& renderAPI = Renderer::GetGraphicAPI();
		switch ( renderAPI )
		{
			case GraphicAPI::OpenGL: return new OpenGLVertexArray();
			case GraphicAPI::Vulkan:
			case GraphicAPI::DirectX11:
			case GraphicAPI::DirectX12:
			NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
		}

		NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Vertex Buffer!" );
		return nullptr;
	}

}  // namespace Normal