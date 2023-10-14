#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

// Normal
#include <Normal/Core/Log.h>
#include <Normal/Core/Timer.h>
#include <Normal/Renderer/Renderer.h>
#include <Normal/Renderer/Renderer2D.h>

// Math Libraries
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Normal/InputManager/KeyboardKeys.h>
#include <Normal/InputManager/MouseInput.h>

// Imgui
#include <imgui.h>


#ifdef NR_PLATFORM_WINDOWS
    #include <Windows.h>
#endif

