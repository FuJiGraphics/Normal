#include "Nrpch.h"
#include "Renderer.h"
#include "Renderer2D.h"

namespace Normal {

	void Renderer::Initialize()
	{
		Renderer2D::Initialze();
	}

	void Renderer::Finalize()
	{
		Renderer2D::Finalize();
	}

	void Renderer::BeginScene( const Own::Share<Camera>& camera )
	{
		m_SceneData.Camera = camera;
	}
	void Renderer::EndScene()
	{

	}

	void Renderer::Submit( const Own::Share<Shader>& shader, 
						   const Own::Share<VertexArray>& vertexArray,
						   const glm::mat4& transform,
						   const glm::vec4& color )
	{
		shader->Bind();
		shader->SetMat4( "u_Transform", transform );
		shader->SetMat4( "u_ViewProj", m_SceneData.Camera->GetVPMatrix() );
		shader->SetFloat4( "u_SquareColor", color );
		vertexArray->Bind();
		RenderCommand::DrawIndexed( vertexArray );
	}


} // namespace Normal