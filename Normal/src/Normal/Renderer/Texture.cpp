#include <Nrpch.h>
#include "Texture.h"
#include "Renderer.h"

#include <Platform/OpenGL/OpenGLTexture.h>

namespace Normal {
    Own::Share<Texture2D> Texture2D::Create( NRint width, NRint height )
    {
        switch ( Renderer::GetGraphicAPI() )
        {
            case RendererAPI::API::OpenGL: return Own::CreateShare<OpenGLTexture2D>( width, height );
            case RendererAPI::API::Vulkan:
            case RendererAPI::API::DirectX11:
            case RendererAPI::API::DirectX12:
                NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
        }

        NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Render Context!" );
        return nullptr;
    }

    Own::Share<Texture2D> Texture2D::Create( const std::string& path )
    {
        switch ( Renderer::GetGraphicAPI() )
        {
            case RendererAPI::API::OpenGL: return Own::CreateShare<OpenGLTexture2D>( path );
            case RendererAPI::API::Vulkan:
            case RendererAPI::API::DirectX11:
            case RendererAPI::API::DirectX12:
                NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
        }

        NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Render Context!" );
        return nullptr;
    }
} // namespace Normal