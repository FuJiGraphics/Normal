#include "Nrpch.h"
#include "RenderContext.h"

#include "Renderer.h"

// TODO: ���߿� API �߰� ��, #include�� ����ȭ�ϱ�. (����ϴ� API�� �°� include �ǵ���)
#include <Platform/OpenGL/OpenGLContext.h>

namespace Normal {
    RenderContext* RenderContext::Create( void* nativeWindow )
    {
        const GraphicAPI& renderAPI = Renderer::GetGraphicAPI();
        switch ( renderAPI )
        {
            case GraphicAPI::OpenGL: return new OpenGLContext( reinterpret_cast<GLFWwindow*>( nativeWindow ) );
            case GraphicAPI::Vulkan:
            case GraphicAPI::DirectX11:
            case GraphicAPI::DirectX12:
                NR_CORE_ASSERT( nullptr, "GraphicAPI::DirectX12 is currently not supported API." );
        }

        NR_CORE_ASSERT( nullptr, "Unexpected Error: Failed to Create Render Context!" );
        return nullptr;
    }

} // namespace Noraml
