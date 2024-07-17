#pragma once

#include <Normal/Core/Core.h>
#include "RendererAPI.h"

namespace Normal {

	// TODO: ��Ƽ�÷��� ���� ���� �������� pImpl idiom ���Ͽ� ���� ��������.

	class NORMAL_API RenderCommand 
	{
	public:
		static void SetBlend( bool enable );

		static void SetClearColor( const glm::vec4& clearColor );
		static void SetViewport( NRint x, NRint y, NRuint width, NRuint height );
		static void Clear();

		static void DrawIndexed( const Own::Share<VertexArray>& vertexArray );
		static void DestroyRendererAPI();
		static void DeleteRenderAPI();

	private:
		// TODO: �ǵ����� 1����Ʈ �޸� ����, ���α׷� ������ ���� �� ���� ���� ��� ���� 
		static RendererAPI* s_RendererAPI;
		// static std::unique_ptr<RendererAPI> s_RendererAPI;
	};

}