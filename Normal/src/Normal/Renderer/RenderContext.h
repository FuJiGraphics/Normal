#pragma once

#include "Normal/Core/Core.h"

namespace Normal {
	
	class NORMAL_API RenderContext
	{
	protected:
		using super = RenderContext;

	public:
		RenderContext() {}
		virtual ~RenderContext() {}

		virtual void InitContext() = 0;
		virtual void SwapBuffers() = 0;

	private:
		NR_SET_NAME( "RenderContext " );
	};

} // namespace Normal