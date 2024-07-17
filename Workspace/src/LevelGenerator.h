#pragma once

#pragma region LevelGenerator
#include "Normal/Core/Core.h"
#include "Normal/Core/Application.h"
#include <vector>

// export defines
#define GENERATE_LAYER(level)\
class ClassGenerate##level\
{\
public:\
	ClassGenerate##level(){\
		Normal::CreateApplication();\
		Application::GetInstance().AttachLevel(new ##(level));\
	}\
};\
class ClassGenerateObject##layer\
{\
private:\
	inline static ClassGenerate##level CLASSGENERATE##level; \
};

#define GENERATE_OVERLAY(level)\
class ClassGenerate##level\
{\
public:\
	ClassGenerate##layer(){\
		Normal::CreateApplication();\
		Application::GetInstance().AttachOverlay(new ##(level));\
	}\
};

#define DESTROY_LAYER(level) { Normal::Application::DetachLevel(level); }
#pragma endregion

// GUI Headers
// #include "LevelHeaders.h"

