#include "Nrpch.h"
#include "Shader.h"

#include "Renderer.h"
#include <Platform/OpenGL/OpenGLShader.h>

namespace Normal {

	Shader* Shader::Create( const std::string& vertexSrc, const std::string& fragmentSrc )
	{
        const GraphicAPI& renderAPI = Renderer::GetGraphicAPI();
        switch ( renderAPI )
        {
            case GraphicAPI::OpenGL: return new OpenGLShader( vertexSrc, fragmentSrc );
            case GraphicAPI::Vulkan:
            case GraphicAPI::DirectX11:
            case GraphicAPI::DirectX12:
            NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
        }

        NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Render Context!" );
        return nullptr;
	}

} // namespace Normal