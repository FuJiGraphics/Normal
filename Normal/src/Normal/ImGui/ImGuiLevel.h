#pragma once

#include "Normal/Core/Core.h"
#include "Normal/Core/Level.h"

struct GLFWwindow;

namespace Normal {

	class NORMAL_API ImGuiLevel : public Level
	{
	public:
		ImGuiLevel();
		virtual ~ImGuiLevel();



		void BeginFrame();
		void EndFrame();

		virtual void OnGuiRender() override;

	protected:
		void CreateImGui();
		void CleanupImGui();

	private:
		GLFWwindow* m_Window      = nullptr;
		bool m_ShowDemoWindow     = true;
		bool m_ShowAnotherWindow  = false;

		float m_ClearColor[4] = { 0.45f, 0.55f, 0.60f, 1.00f };
		double m_Time = 0.0;

		NR_SET_NAME( "ImGuiLevel" );
	};

} // namespace Normal