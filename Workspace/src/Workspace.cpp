#include <NormalEngine.h>

namespace Normal {


	class Workspace : public Application
	{
	public:
		Workspace()
		{
			super::AttachOverlay( new ImGuiLevel );
			

		}
		~Workspace()
		{

		}


	};

	Normal::Application* Normal::CreateApplication()
	{

		return new Workspace();
	}


} // namespace Normal