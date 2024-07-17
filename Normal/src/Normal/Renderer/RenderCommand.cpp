#include "Nrpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Normal {

	RendererAPI* RenderCommand::s_RendererAPI = nullptr;

	void RenderCommand::SetBlend( bool enable )
	{
		if (s_RendererAPI == nullptr)
			s_RendererAPI = new OpenGLRendererAPI();
		s_RendererAPI->SetBlend( enable );
	}

	void RenderCommand::SetClearColor( const glm::vec4& clearColor )
	{
		if (s_RendererAPI == nullptr)
			s_RendererAPI = new OpenGLRendererAPI();
		s_RendererAPI->SetClearColor( clearColor );
	}

	void RenderCommand::SetViewport( NRint x, NRint y, NRuint width, NRuint height )
	{
		if (s_RendererAPI == nullptr)
			s_RendererAPI = new OpenGLRendererAPI();
		if (width <= 0 || height <= 0 || width < x || height < y)
		{
			NR_CORE_ERROR( "ERROR INFO -> inline static void SetViewport( {0}, {1}, {2}, {3} )"
				, x, y, width, height );
			NR_CORE_ASSERT( false, "ERROR: Non-allowed parameter in function!" );
		}
		s_RendererAPI->SetViewport( x, y, width, height );
	}

	void RenderCommand::Clear()
	{
		if (s_RendererAPI == nullptr)
			s_RendererAPI = new OpenGLRendererAPI();
		s_RendererAPI->Clear();
	}

	void RenderCommand::DrawIndexed( const Own::Share<VertexArray>& vertexArray )
	{
		if (s_RendererAPI == nullptr)
			s_RendererAPI = new OpenGLRendererAPI();
		s_RendererAPI->DrawIndexed( vertexArray );
	}

	void RenderCommand::DestroyRendererAPI()
	{
		if (s_RendererAPI)
		{
			delete s_RendererAPI;
			s_RendererAPI = nullptr;
		}
	}

	void RenderCommand::DeleteRenderAPI()
	{
		if (s_RendererAPI)
		{
			delete s_RendererAPI;
			s_RendererAPI = nullptr;
		}
	}



} // namespace Normal