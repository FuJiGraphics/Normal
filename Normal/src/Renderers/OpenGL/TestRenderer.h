#pragma once

#include "Normal/Core/Core.h"
#include "Normal/Core/Level.h"

struct GLFWwindow;
struct ImGuiIO;
struct ImVec4;

namespace Normal {

	class NORMAL_API TestRenderer : public Level
	{
	public:
		TestRenderer();
		~TestRenderer();
		virtual void OnEvent( Event& event ) override;
		virtual void OnUpdate( float deltaTime ) override;
		virtual void OnRender() override;

		static void glfw_error_callback( int error, const char* description );

	private:
		GLFWwindow* window;
		const char* glsl_version;
		ImGuiIO* io;

		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4& clear_color;
	};


} // namespace 