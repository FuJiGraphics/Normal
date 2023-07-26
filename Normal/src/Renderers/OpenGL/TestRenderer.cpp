#include "Nrpch.h"
#include "TestRenderer.h"

// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs


#include "imgui.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_opengl3_loader.h"

#include <stdio.h>


namespace Normal {

    static ImVec4 gImvec( 0.45f, 0.55f, 0.60f, 1.00f );

	void TestRenderer::glfw_error_callback( int error, const char* description )
	{
		fprintf( stderr, "GLFW Error %d: %s\n", error, description );
	}

	TestRenderer::TestRenderer() 
        : io ( nullptr )
        , clear_color( gImvec )
	{
        glfwSetErrorCallback( glfw_error_callback );

        // GL 3.0 + GLSL 130
        glsl_version = "#version 130";
        glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
        glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );

        // Create window with graphics context
        window = glfwGetCurrentContext();
        NR_CORE_ASSERT( window, "Failed to initialize window." );

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext(); 
        io = &ImGui::GetIO();
        (void)(*io);
        io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL( window, true );
        ImGui_ImplOpenGL3_Init( glsl_version );
	}

	TestRenderer::~TestRenderer()
	{
        // cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        glfwDestroyWindow( window );
        glfwTerminate();

	}

	void TestRenderer::OnEvent( Event& event )
	{

	}

    void TestRenderer::OnUpdate( float deltaTime )
    {
        if ( !glfwWindowShouldClose( window ) )
        {

            // Start the Dear ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
            if ( show_demo_window )
                ImGui::ShowDemoWindow( &show_demo_window );

            // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.

            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin( "Hello, world!" );                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text( "This is some useful text." );               // Display some text (you can use a format strings too)
            ImGui::Checkbox( "Demo Window", &show_demo_window );      // Edit bools storing our window open/close state
            ImGui::Checkbox( "Another Window", &show_another_window );

            ImGui::SliderFloat( "float", &f, 0.0f, 1.0f );            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3( "clear color", (float*)&clear_color ); // Edit 3 floats representing a color

            if ( ImGui::Button( "Button" ) )                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text( "counter = %d", counter );

            ImGui::Text( "Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io->Framerate, io->Framerate );
            ImGui::End();


            // 3. Show another simple window.
            if ( show_another_window )
            {
                ImGui::Begin( "Another Window", &show_another_window );   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
                ImGui::Text( "Hello from another window!" );
                if ( ImGui::Button( "Close Me" ) )
                    show_another_window = false;
                ImGui::End();
            }

            // Rendering
            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize( window, &display_w, &display_h );
            glViewport( 0, 0, display_w, display_h );
            glClearColor( clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w );
            glClear( GL_COLOR_BUFFER_BIT );
            ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );
        }
    }

	void TestRenderer::OnRender()
	{

	}

} // namespace Normal