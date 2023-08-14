#include <NormalEngine.h>
#include "Rectangle/Rectangle.h"

namespace Normal {

	class Workspace : public Application
	{
	public:
		Workspace()
		{
			super::AttachLevel(new Rectangle);
		}
		~Workspace()
		{
			super::DetachLevel(new Rectangle);
		}


	};

	Normal::Application* Normal::CreateApplication()
	{
		return new Workspace();
	}


} // namespace Normal