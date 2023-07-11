#pragma once
#include "Core.h"

namespace Normal {

class NORMAL_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();
};

// To be defined in CLIENT
Application* CreateApplication();

} // namespace Normal
