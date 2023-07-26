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
		void OnEvent( Event& event );
		void OnUpdate( float deltaTime );
		void OnRender();

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