#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Core/Level.h>
#include "Rectangle\Rectangle.h"

namespace Normal {
	class NORMAL_API World : public Level
	{
	public:
		virtual void OnUpdate( float deltaTime ) override;


	private:
		Rectangle m_Rec;
	};

}

