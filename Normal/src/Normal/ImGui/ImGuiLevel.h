#pragma once

#include "Normal/Core/Core.h"
#include "Normal/Core/Level.h"

struct GLFWwindow;

namespace Normal {

#pragma region Forward
	class MouseInput;
	class KeyInput;
	struct MouseInputData;
	struct KeyInputData;
#pragma endregion 

	class NORMAL_API ImGuiLevel : public Level
	{
	public:
		ImGuiLevel();
		virtual ~ImGuiLevel();

		virtual void OnEvent( Event& event ) override;
		virtual void OnUpdate( float deltaTime ) override;
		virtual void OnRender() override;

		void OnMousePressedImpl( MouseInputData input );
		void OnMouseReleasedImpl( MouseInputData input );
		void OnMouseScrolledImpl( MouseInputData input );
		void OnMouseMovedImpl( MouseInputData input );
		void OnKeyPressedImpl( KeyInputData input );

	protected:
		void Initialize();
		void Destroy();

	private:
		GLFWwindow* m_Window;

		MouseInput& m_MouseInput;
		KeyInput& m_KeyboardInput;


		double m_Time = 0.0;

		NR_SET_NAME( "ImGui_Level" );
	};

} // namespace Normal