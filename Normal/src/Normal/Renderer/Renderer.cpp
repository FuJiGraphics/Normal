#include "Nrpch.h"
#include "Renderer.h"

namespace Normal {

	void Renderer::BeginScene( const std::shared_ptr<Camera>& camera )
	{
		m_SceneData.Camera = camera;
	}
	void Renderer::EndScene()
	{

	}

	void Renderer::Submit( const std::shared_ptr<Shader>& shader, 
						   const std::shared_ptr<VertexArray>& vertexArray )
	{
		shader->Bind();
		shader->UploadUniformMat4( "u_ViewProj", m_SceneData.Camera->GetVPMatrix() );
		vertexArray->Bind();
		RenderCommand::DrawIndexed( vertexArray );
	}


} // namespace Normal