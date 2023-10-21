#include "Normal/Core/Core.h"
#include "Normal/Renderer/RenderContext.h"

struct GLFWwindow;

namespace Normal {

	class NORMAL_API OpenGLContext : public RenderContext
	{
	public:
		explicit OpenGLContext( void* window );
		virtual ~OpenGLContext();

	public:
		virtual void InitContext() override;
		virtual void SwapBuffers() override;

	private:
		void ShowRendererProps() const;

	private:
		GLFWwindow* m_Window;

		NR_SET_NAME( "OpenGLContext" );
	};



} // namespace Normal