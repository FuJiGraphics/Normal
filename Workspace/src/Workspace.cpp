#include <NormalEngine.h>

#include <imgui.h>

namespace Normal {

	class ExampleLevel : public Level
	{
	public:
		ExampleLevel() 
		{
			NR_CLIENT_INFO_CTOR_N( super::GetLevelCount() );
		}
		~ExampleLevel() 
		{
			NR_CLIENT_INFO_DTOR_N( super::GetLevelCount() );
		}

		virtual void OnUpdate( float deltaTime ) override
		{
			
		}

		virtual void OnGuiRender() override
		{
			ImGui::Begin( "test" );
			ImGui::Text( "te" );
			ImGui::End();
		}

	private:
		NR_SET_NAME( "Example Level" );
	};

	class Workspace : public Application
	{
	public:
		Workspace()
		{
			super::AttachOverlay( new ExampleLevel() );
		}
		~Workspace()
		{

		}


	};

	Normal::Application* Normal::CreateApplication()
	{

		return new Workspace();
	}


} // namespace Normal