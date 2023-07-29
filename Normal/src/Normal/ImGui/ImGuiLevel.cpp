#include "Nrpch.h"
#include "ImGuiLevel.h"

#include "Normal/Core/Window.h"
#include "Normal/Core/Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "Renderers/OpenGL/imgui_impl_opengl3.h"

#include "Normal/Events/KeyEvent.h"
#include "Normal/Events/MouseEvent.h"

#include "Normal/InputManager/MouseInput.h"
#include "Normal/InputManager/KeyInput.h"

namespace Normal {


	ImGuiLevel::ImGuiLevel()
		: m_Window( nullptr )
		, m_MouseInput( MouseInput::GetInstance() )
		, m_KeyboardInput( KeyInput::GetInstance() )
	{
		Initialize();
	}

	ImGuiLevel::~ImGuiLevel()
	{
		Destroy();
	}

	void ImGuiLevel::OnEvent( Event& event )
	{
		m_MouseInput.OnEvent( event );
		m_KeyboardInput.OnEvent( event );
	}

	void ImGuiLevel::OnUpdate( float deltaTime )
	{
		ImGuiIO& io = ImGui::GetIO();
		auto& app = Application::GetInstance();

		// Setup display size (every frame to accommodate for window resizing)
		// glfwGetWindowSize( m_Window, &w, &h );
		// glfwGetFramebufferSize( m_Window, &display_w, &display_h );
		io.DisplaySize = ImVec2( (float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight() );
		
		// Setup time step
		double current_time = glfwGetTime();
		if ( current_time <= m_Time ) current_time = m_Time + 0.00001f;
		io.DeltaTime = m_Time > 0.0 ? (float)( current_time - m_Time ) : (float)( 1.0f / 60.0f );
		m_Time = current_time;
		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		bool showDemoWindow = true;
		ImGui::ShowDemoWindow( &showDemoWindow );
	}

	void ImGuiLevel::OnRender()
	{
		ImGui::Render();
		glClear( GL_COLOR_BUFFER_BIT );
		ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );
	}

	void ImGuiLevel::OnMousePressedImpl( MouseInputData input )
	{
		// NR_CORE_INFO( "Pressed Mouse Button = {0}", input.keycode );
		ImGuiIO& io = ImGui::GetIO();
		io.AddMouseButtonEvent( input.keycode, true );
	}

	void ImGuiLevel::OnMouseReleasedImpl( MouseInputData input )
	{
		// NR_CORE_TRACE( "Released Mouse Button = {0}", input.keycode );
		ImGuiIO& io = ImGui::GetIO();
		io.AddMouseButtonEvent( input.keycode, false );
	}

	void ImGuiLevel::OnMouseScrolledImpl( MouseInputData input )
	{
		// NR_CORE_TRACE( "Scrolled xOffset = {0}, yOffset = {1}", input.xOffset, input.yOffset );
		ImGuiIO& io = ImGui::GetIO();
		io.AddMouseWheelEvent( input.xOffset, input.yOffset );
	}

	void ImGuiLevel::OnMouseMovedImpl( MouseInputData input )
	{
		// NR_CORE_TRACE( "Mouse Position x = {0}, y = {1}", input.xOffset, input.yOffset );
		ImGuiIO& io = ImGui::GetIO();
		io.AddMousePosEvent( input.xOffset, input.yOffset );
	}

	void ImGuiLevel::OnKeyPressedImpl( KeyInputData input )
	{
		// NR_CORE_INFO( "Pressed key {0}", (char)input.keycode );
		ImGuiIO& io = ImGui::GetIO();
		io.AddInputCharacter( input.keycode );
	}

	void ImGuiLevel::Initialize()
	{
		auto& app = Application::GetInstance();
		m_Window = static_cast<GLFWwindow*>( app.GetWindow().GetNativeWindow() );

		// Setup Dear ImGui Context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsLight();

		// Setup Platform/Renderer backends
		ImGui_ImplOpenGL3_Init( "#version 130" );

		m_MouseInput.AttachCallback( BIND_EVENT_FUNC( ImGuiLevel::OnMousePressedImpl ), MouseInput::Type::IsPressed );
		m_MouseInput.AttachCallback( BIND_EVENT_FUNC( ImGuiLevel::OnMouseReleasedImpl ), MouseInput::Type::IsReleased );
		m_MouseInput.AttachCallback( BIND_EVENT_FUNC( ImGuiLevel::OnMouseScrolledImpl ), MouseInput::Type::IsScrolled );
		m_MouseInput.AttachCallback( BIND_EVENT_FUNC( ImGuiLevel::OnMouseMovedImpl ), MouseInput::Type::IsMoved );

		m_KeyboardInput.AttachCallback( BIND_EVENT_FUNC( ImGuiLevel::OnKeyPressedImpl ), KeyInput::Type::IsPressed );
	}

	void ImGuiLevel::Destroy()
	{
		// Cleanup
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();
	}

} // namespace Normal