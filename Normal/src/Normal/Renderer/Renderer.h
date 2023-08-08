#pragma once

#include <Normal/Core/Core.h>

namespace Normal {

	enum class GraphicAPI
	{
		none = 0,
		OpenGL, Vulkan, 
		DirectX11, DirectX12, 
	};

	class NORMAL_API Renderer 
	{
	protected:
		explicit Renderer() = default;
	public:
		~Renderer() = default;

	public:
		inline static GraphicAPI GetGraphicAPI() { return s_RenderAPI; }

	private:
		static GraphicAPI s_RenderAPI;
	};


} // namespace Normal