#include <NormalEngine.h>
#include "World/World.h"

namespace Normal {

	class NORMAL_API Workspace : public Application
	{
	public:
		Workspace()
		{
			super::AttachLevel( new World );
		}
		~Workspace()
		{
		}

	private:

	};

	Normal::Application* Normal::CreateApplication()
	{
		return new Workspace();
	}


} // namespace Normal