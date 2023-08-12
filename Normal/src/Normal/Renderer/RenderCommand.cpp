#include "Nrpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Normal {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();


}