#pragma once
#ifndef __NORMAL_ENGINE_H__
#define __NORMAL_ENGINE_H__

// Imgui
#include <imgui.h>

// standards
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

// Math Libraries
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

// ------ For use by Normal applications ------
#include <Normal/Core/Log.h>
#include <Normal/Core/Core.h>
#include <Normal/Core/Application.h>
#include <Normal/Core/Level.h>
#include <Normal/Core/Timer.h>
#include <Normal/ImGui/ImGuiLevel.h>

// Input Manager Interfaces
#include <Normal/InputManager/MouseInput.h>
#include <Normal/InputManager/MouseKeys.h>
#include <Normal/InputManager/KeyboardKeys.h>

// For use by Rendering
#include <Normal/Renderer/Renderer.h>
#include <Normal/Renderer/Renderer2D.h>
#include <Normal/Renderer/RenderContext.h>
#include <Normal/Renderer/RenderCommand.h>
#include <Normal/Renderer/RendererAPI.h>
#include <Normal/Renderer/Texture.h>
#include <Normal/Renderer/Camera.h>
#include <Normal/Renderer/CameraManager.h>
#include <Normal/Renderer/Buffer.h>
#include <Normal/Renderer/VertexArray.h>
#include <Normal/Renderer/Shader.h>
// -------------------------------------------

#include <Normal/Core/EntryPoint.h>
#include <LevelGenerator.h>

#endif /*__NORMAL_ENGINE_H__*/