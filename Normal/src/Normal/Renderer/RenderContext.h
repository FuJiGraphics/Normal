#pragma once

#include <Normal/Core/Core.h>

namespace Normal {
	
	class NORMAL_API RenderContext
	{
	protected:
		explicit RenderContext() = default;
	public:
		virtual ~RenderContext() = default;

	public:
		virtual void InitContext() = 0;
		virtual void SwapBuffers() = 0;

	    static RenderContext* Create( void* nativeWindow );

	};

} // namespace Normal