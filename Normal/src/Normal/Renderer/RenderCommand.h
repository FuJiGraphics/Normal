#pragma once

#include <Normal/Core/Core.h>
#include "RendererAPI.h"

namespace Normal {

	// TODO: 멀티플랫폼 관련 개선 사항으로 pImpl idiom 패턴에 대해 공부하자.

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
		// TODO: 의도적인 1바이트 메모리 누수, 프로그램 수명이 다할 때 까지 남길 방법 강구 
		static RendererAPI* s_RendererAPI;
		// static std::unique_ptr<RendererAPI> s_RendererAPI;
	};

}