#include "Nrpch.h"
#include "ImGuiLevel.h"

#include "Normal/Core/Application.h"
#include "Normal/Core/Window.h"

#include <imgui.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

namespace Normal {

	
	ImGuiLevel::ImGuiLevel()
	{
		CreateImGui();
		NR_CORE_INFO_CTOR;
	}

	ImGuiLevel::~ImGuiLevel()
	{
		CleanupImGui();
		NR_CORE_INFO_DTOR;
	}

	void ImGuiLevel::BeginFrame()
	{
		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLevel::EndFrame()
	{
		ImGuiIO& io = ImGui::GetIO();

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize( m_Window, &display_w, &display_h );
		glViewport( 0, 0, display_w, display_h );
		glClearColor( m_ClearColor[0] * m_ClearColor[3], 
					  m_ClearColor[1] * m_ClearColor[3], 
					  m_ClearColor[2] * m_ClearColor[3], 
					  m_ClearColor[3] );
		glClear( GL_COLOR_BUFFER_BIT );
		ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );

		// Update and Render additional Platform Windows
		// (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
		//  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
		if ( io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable )
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent( backup_current_context );
		}

	}

	void ImGuiLevel::OnGuiRender()
	{
		if ( m_ShowDemoWindow )
			ImGui::ShowDemoWindow();

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
		{
			const ImGuiIO& io = ImGui::GetIO();

			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin( "Hello, world!" );                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text( "This is some useful text." );               // Display some text (you can use a format strings too)
			ImGui::Checkbox( "Demo Window", &m_ShowDemoWindow );      // Edit bools storing our window open/close state
			ImGui::Checkbox( "Another Window", &m_ShowAnotherWindow );

			ImGui::SliderFloat( "float", &f, 0.0f, 1.0f );            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3( "clear color", (float*)&m_ClearColor ); // Edit 3 floats representing a color

			if ( ImGui::Button( "Button" ) )                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text( "counter = %d", counter );

			ImGui::Text( "Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate );
			ImGui::End();
		}

		// 3. Show another simple window.
		if ( m_ShowAnotherWindow )
		{
			ImGui::Begin( "Another Window", &m_ShowAnotherWindow );   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text( "Hello from another window!" );
			if ( ImGui::Button( "Close Me" ) )
				m_ShowAnotherWindow = false;
			ImGui::End();
		}
	}

	void ImGuiLevel::CreateImGui()
	{
		// Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
	// GL ES 2.0 + GLSL 100
		const char* glsl_version = "#version 100";
		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );
		glfwWindowHint( GLFW_CLIENT_API, GLFW_OPENGL_ES_API );
#elif defined(__APPLE__)
	// GL 3.2 + GLSL 150
		const char* glsl_version = "#version 150";
		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 2 );
		glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );  // 3.2+ only
		glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );            // Required on Mac
#else
	// GL 3.0 + GLSL 130
		const char* glsl_version = "#version 130";
		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );
		//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif
		// Create window with graphics context
		const auto& app = Application::GetInstance();
		m_Window = static_cast<GLFWwindow*>( app.GetWindow().GetNativeWindow() );
		glfwMakeContextCurrent( m_Window );
		
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
	
		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsLight();

			// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if ( io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable )
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		// Setup Platform/Renderer backends
		ImGui_ImplGlfw_InitForOpenGL( m_Window, true );
		ImGui_ImplOpenGL3_Init( glsl_version );
	}

	void ImGuiLevel::CleanupImGui()
	{
		// Cleanup
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

} // namespace Normal