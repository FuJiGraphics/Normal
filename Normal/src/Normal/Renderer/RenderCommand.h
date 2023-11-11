#pragma once

#include <Normal/Core/Core.h>
#include "RendererAPI.h"

namespace Normal {

	// TODO: ��Ƽ�÷��� ���� ���� �������� pImpl idiom ���Ͽ� ���� ��������.

	class NORMAL_API RenderCommand 
	{
	public:
		inline static void SetBlend( bool enable )
		{
			s_RendererAPI->SetBlend( enable );
		}

		inline static void SetClearColor( const glm::vec4& clearColor )
		{
			s_RendererAPI->SetClearColor( clearColor );
		}

		inline static void SetViewport( NRint x, NRint y, NRuint width, NRuint height )
		{
			if ( width <= 0 || height <= 0 || width < x || height < y )
			{
				NR_CORE_ERROR( "ERROR INFO -> inline static void SetViewport( {0}, {1}, {2}, {3} )"
							   , x, y, width, height );
				NR_CORE_ASSERT( false, "ERROR: Non-allowed parameter in function!" );
			}
			s_RendererAPI->SetViewport( x, y, width, height );
		}

		inline static void Clear()
		{
			s_RendererAPI->Clear();
		}

		inline static void DrawIndexed( const Own::Share<VertexArray>& vertexArray )
		{
			s_RendererAPI->DrawIndexed( vertexArray );
		}
		
		inline static void DestroyRendererAPI()
		{
			delete s_RendererAPI;
		}

		inline static void DeleteRenderAPI()
		{
			delete s_RendererAPI;
		}

	private:
		// TODO: �ǵ����� 1����Ʈ �޸� ����, ���α׷� ������ ���� �� ���� ���� ��� ���� 
		static RendererAPI* s_RendererAPI;
		// static std::unique_ptr<RendererAPI> s_RendererAPI;
	};

}