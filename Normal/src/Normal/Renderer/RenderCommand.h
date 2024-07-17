#pragma once

#include <Normal/Core/Core.h>
#include "RendererAPI.h"

namespace Normal {

	// TODO: 멀티플랫폼 관련 개선 사항으로 pImpl idiom 패턴에 대해 공부하자.

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
		// TODO: 의도적인 1바이트 메모리 누수, 프로그램 수명이 다할 때 까지 남길 방법 강구 
		static RendererAPI* s_RendererAPI;
		// static std::unique_ptr<RendererAPI> s_RendererAPI;
	};

}