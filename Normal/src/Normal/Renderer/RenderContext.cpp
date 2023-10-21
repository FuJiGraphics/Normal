#include "Nrpch.h"
#include "RenderContext.h"

#include "Renderer.h"

// TODO: 나중에 API 추가 시, #include문 최적화하기. (사용하는 API에 맞게 include 되도록)
#include <Platform/OpenGL/OpenGLContext.h>

namespace Normal {
    Own::Share<RenderContext> RenderContext::Create( void* nativeWindow )
    {
        switch ( Renderer::GetGraphicAPI() )
        {
            case RendererAPI::API::OpenGL: return Own::CreateShare<OpenGLContext>( nativeWindow );
            case RendererAPI::API::Vulkan:
            case RendererAPI::API::DirectX11:
            case RendererAPI::API::DirectX12:
                NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
        }

        NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Render Context!" );
        return nullptr;
    }

} // namespace Noraml
