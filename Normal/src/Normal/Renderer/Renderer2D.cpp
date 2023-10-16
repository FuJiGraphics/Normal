#include <Nrpch.h>
#include "Renderer2D.h"
#include "Renderer.h"
#include "CameraManager.h"
#include "Shader.h"
#include "Texture.h"
#include <Normal/Diagram/PrimitiveGeometry.h>

namespace Normal {

	static Render2DStorage* s_Storage = nullptr;

	void Renderer2D::Initialze()
	{
		Quad2D colorQuad;
		Quad2D textureQuad( true );

		s_Storage = new Render2DStorage();
		s_Storage->ColorVAO = colorQuad.GetVertexArray();
		s_Storage->TextureVAO = textureQuad.GetVertexArray();

		ShaderPaths paths;
		paths.VertPath = "asset/shaders/color/Vertex.glsl";
		paths.FragPath = "asset/shaders/color/Fragment.glsl";
		s_Storage->ShaderManager.Add( "ColorShader", Shader::Create( paths ) );
		paths.VertPath = "asset/shaders/texture/Vertex.glsl";
		paths.FragPath = "asset/shaders/texture/Fragment.glsl";
		s_Storage->ShaderManager.Add( "TextureShader", Shader::Create( paths ) );

		NR_CORE_ASSERT( s_Storage, "Failed to initialized Renderer2D!!" );
		RenderCommand::SetClearColor( { 0.2f, 0.2f, 0.2f, 1.0f } );
	}

	void Renderer2D::Finalize()
	{
		NR_CORE_ASSERT( s_Storage, "Did not found s_Quad Memory!!" );
		delete s_Storage;
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

	void Renderer2D::DrawQuad( const glm::vec2& pos, const glm::vec2& scale, const glm::vec4& color )
	{
		DrawQuad( glm::vec3{pos, 0.0f}, scale, color );
	}

	void Renderer2D::DrawQuad( const glm::vec3& pos, const glm::vec2& scale, const glm::vec4& color )
	{
		glm::mat4 transform =
			glm::translate( glm::mat4( 1.0f ), pos ) *
			glm::scale( glm::mat4( 1.0f ), glm::vec3( scale, 1.0f ) );

		Own::Share<Shader>& shader = s_Storage->ShaderManager["ColorShader"];
		shader->Bind();
		shader->SetMat4( "u_Transform", transform );
		shader->SetFloat4( "u_SquareColor", color );
		Renderer::Submit( shader, s_Storage->ColorVAO );
	}

	void Renderer2D::DrawQuad( const glm::vec2& pos, const glm::vec2& scale, const Own::Share<Texture2D>& texture )
	{
		DrawQuad( glm::vec3{pos, 0.0f}, scale, texture );
	}

	void Renderer2D::DrawQuad( const glm::vec3& pos, const glm::vec2& scale, const Own::Share<Texture2D>& texture )
	{
		glm::mat4 transform = 
			glm::translate( glm::mat4( 1.0f ), pos ) * 
			glm::scale( glm::mat4( 1.0f ), glm::vec3( scale, 1.0f ) );

		Own::Share<Shader>& shader = s_Storage->ShaderManager["TextureShader"];
		shader->Bind();
		shader->SetMat4( "u_Transform", transform );
		shader->SetInt( "u_Texture", 0 );
		texture->Bind();
		Renderer::Submit( shader, s_Storage->TextureVAO );
	}

} // namespace Normal