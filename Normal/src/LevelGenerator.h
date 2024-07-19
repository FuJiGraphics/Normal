#pragma once

#pragma region LevelGenerator

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
	ClassGenerate##level(){\
		Normal::CreateApplication();\
		Application::GetInstance().AttachOverlay(new ##(level));\
	}\
};\
class ClassGenerateObject##level\
{\
private:\
	inline static ClassGenerate##level CLASSGENERATE##level; \
};

#define DESTROY_LAYER(level) { Normal::Application::DetachLevel(level); }
#pragma endregion


