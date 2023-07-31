#include <NormalEngine.h>

namespace Normal {

	class ExampleLevel : public Level
	{
	public:
		ExampleLevel() {}
		~ExampleLevel() {}

		virtual void OnUpdate( float deltaTime ) 
		{
			auto& keyInput = KeyInput::GetInstance();

			if ( keyInput.IsKeyPreesed( NR_KEY_T ) )
			{
				NR_CLIENT_TRACE( "Pressed Key = {0}", (char)NR_KEY_T );
			}
		};

	private:

	};

	class Workspace : public Application
	{
	public:
		Workspace()
		{
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