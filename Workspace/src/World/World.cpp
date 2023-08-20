#include "World.h"
#include <Normal/Renderer/Renderer.h>

namespace Normal {
	void World::OnUpdate( float deltaTime )
	{
		Renderer::BeginScene();
		RenderCommand::Clear();
		RenderCommand::SetClearColor( { 0.2f, 0.2f, 0.2f, 1.0f } );

		Renderer::Submit( m_Rec.GetVertexArray() );

		Renderer::EndScene();
	}

}
