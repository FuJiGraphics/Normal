#include <Nrpch.h>
#include "Renderer2D.h"
#include "Renderer.h"
#include "CameraManager.h"
#include <Normal/Diagram/PrimitiveGeometry.h>

namespace Normal {

	static Quad* s_Quad = nullptr;

	void Renderer2D::Initialze()
	{
		s_Quad = new Quad;
		NR_CORE_ASSERT( s_Quad, "Failed to initialized Renderer2D!!" );
		RenderCommand::SetClearColor( { 0.2f, 0.2f, 0.2f, 1.0f } );
	}

	void Renderer2D::Finalize()
	{
		NR_CORE_ASSERT( s_Quad, "Did not found s_Quad Memory!!" );
		delete s_Quad;
	}

	void Renderer2D::BeginScene( const CameraManager& cameraManager )
	{
		Renderer::BeginScene( cameraManager.GetCamera() );
		RenderCommand::Clear();
	}

	void Renderer2D::BeginScene( const Own::Share<CameraManager>& cameraManager )
	{
		Renderer::BeginScene( cameraManager->GetCamera() );
		RenderCommand::Clear();
	}

	void Renderer2D::EndScene()
	{
		// TODO : End Scene ±¸Çö
	}

	void Renderer2D::DrawQuad( const glm::vec3& pos, const glm::vec2& scale, const glm::vec4& color )
	{
		glm::mat4 transform = 
			glm::scale( glm::mat4( 1.0f ), glm::vec3( scale, 1.0f ) ) * 
			glm::translate( glm::mat4( 1.0f ), pos );

		Renderer::Submit( s_Quad->GetShader(), s_Quad->GetVertexArray(),
						  transform, color );
	}

	void Renderer2D::DrawQuad( const glm::vec2& pos, const glm::vec2& scale, const glm::vec4& color )
	{
		glm::mat4 transform =
			glm::translate( glm::mat4( 1.0f ), glm::vec3( pos, 1.0f ) ) *
			glm::scale( glm::mat4( 1.0f ), glm::vec3( scale, 1.0f ) );

		Renderer::Submit( s_Quad->GetShader(), s_Quad->GetVertexArray(),
						  transform, color );
	}

} // namespace Normal