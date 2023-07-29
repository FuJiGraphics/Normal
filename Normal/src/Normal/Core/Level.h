#pragma once

#include "Core.h"
#include "Normal/Events/Event.h"

namespace Normal {

	class Mouse;
	class Keyboard;

	class NORMAL_API Level
	{
	public:
		Level() { }
		virtual ~Level() { }

		virtual void OnAttach() {};
		virtual void OnDetach() {};

		virtual void OnEvent( Event& event ) {};
		virtual void OnUpdate( float deltaTime ) {};
		virtual void OnRender() {};


		// virtual std::string GetName() const { return NR_GET_NAME; }
	private:
		// std::unique_ptr<Normal::Mouse> m_MouseManager;
		NR_SET_NAME( "Level" );
	};



} // namespace Normal