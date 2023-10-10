#include "Nrpch.h"
#include "Shader.h"

#include "Renderer.h"
#include <Platform/OpenGL/OpenGLShader.h>

namespace Normal {

    Shader* Shader::Create( const ShaderPaths& paths )
    {
        switch ( Renderer::GetGraphicAPI() )
        {
            case RendererAPI::API::OpenGL: return new OpenGLShader( paths );
            case RendererAPI::API::Vulkan:
            case RendererAPI::API::DirectX11:
            case RendererAPI::API::DirectX12:
                NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
        }

        NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Render Context!" );
        return nullptr;
    }

	Shader* Shader::Create( const std::string& vertexSrc, const std::string& fragmentSrc )
	{
        switch ( Renderer::GetGraphicAPI() )
        {
            case RendererAPI::API::OpenGL: return new OpenGLShader( vertexSrc, fragmentSrc );
            case RendererAPI::API::Vulkan:
            case RendererAPI::API::DirectX11:
            case RendererAPI::API::DirectX12:
            NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
        }

        NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Render Context!" );
        return nullptr;
	}

    void ShaderManager::Add( const std::string& name, Shader* shader )
    {
        NR_CORE_ASSERT( !this->Exist( name ), "Shader data already exists! " );
        m_Shaders.insert( std::make_pair( name, Own::Share<Shader>( shader ) ) );
    }

    bool ShaderManager::Exist( const std::string& name ) const
    {
        return m_Shaders.find( name ) != m_Shaders.end();
    }

} // namespace Normal