#include "Normal/Core/Core.h"
#include "Normal/Renderer/RenderContext.h"

struct GLFWwindow;

namespace Normal {

	class NORMAL_API OpenGLContext : public RenderContext
	{
	public:
		OpenGLContext( GLFWwindow* window );
		virtual ~OpenGLContext();

		virtual void InitContext() override;
		virtual void SwapBuffers() override;

	protected:
		void ShowRendererProps() const;

	private:
		GLFWwindow* m_Window;

		NR_SET_NAME( "OpenGLContext" );
	};



} // namespace Normal