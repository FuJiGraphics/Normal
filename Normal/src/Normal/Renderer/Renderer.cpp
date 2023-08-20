#include "Nrpch.h"
#include "Renderer.h"

namespace Normal {

	void Renderer::BeginScene( const Camera& camera )
	{

	}
	void Renderer::EndScene()
	{

	}
	void Renderer::Submit( const std::shared_ptr<VertexArray>& vertexArray )
	{
		vertexArray->Bind();
		RenderCommand::DrawIndexed( vertexArray );
	}


} // namespace Normal