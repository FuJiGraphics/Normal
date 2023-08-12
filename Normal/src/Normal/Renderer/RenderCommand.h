#pragma once

#include <Normal/Core/Core.h>
#include "RendererAPI.h"

namespace Normal {

	// TODO: ��Ƽ�÷��� ���� ���� �������� pImpl idiom ���Ͽ� ���� ��������.

	class NORMAL_API RenderCommand 
	{
	public:
		inline static void SetClearColor( const glm::vec4& clearColor )
		{
			s_RendererAPI->SetClearColor( clearColor );
		}

		inline static void Clear()
		{
			s_RendererAPI->Clear();
		}

		inline static void DrawIndexed( const std::shared_ptr<VertexArray>& vertexArray )
		{
			s_RendererAPI->DrawIndexed( vertexArray );
		}

	private:
		// TODO: �ǵ����� 1����Ʈ �޸� ����, ���α׷� ������ ���� �� ���� ���� ��� ���� 
		static RendererAPI* s_RendererAPI;
		// static std::unique_ptr<RendererAPI> s_RendererAPI;
	};

}