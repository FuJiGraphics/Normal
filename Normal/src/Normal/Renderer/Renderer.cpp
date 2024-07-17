#include "Nrpch.h"
#include "Renderer.h"
#include "Renderer2D.h"

namespace Normal {

	void Renderer::Initialize()
	{
		if (Renderer2D::IsInitialized() == false)
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
						   const Own::Share<VertexArray>& vertexArray )
	{
		shader->Bind();
		shader->SetMat4( "u_ViewProj", m_SceneData.Camera->GetVPMatrix() );
		vertexArray->Bind();
		RenderCommand::DrawIndexed( vertexArray );
	}

} // namespace Normal