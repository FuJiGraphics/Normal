#pragma once

#include <Normal/Core/Core.h>
#include <glm/glm.hpp>
#include <memory>

#include "VertexArray.h"

namespace Normal {

	/*
	RendererAPI�� OpenGL�� DirectX ���� �� �� ���� �� ���̰� 
	RenderAPI�� �ٸ��� Renderer���� ���� API�̴�. ��Ī�� �������� �и��� �ν�����.
	*/
	class NORMAL_API RendererAPI
	{
	public:
		enum class API
		{
			None = 0,
			OpenGL, Vulkan,
			DirectX11, DirectX12,
		};

	public:
		virtual void SetClearColor( const glm::vec4& clearColor ) = 0;
		virtual void Clear() = 0;

		// Index Buffer�� �̿��ؼ� Scene�� Draw ����� �����ϱ� ������ DrawIndexed��� �̸��� �ȴ�.
		virtual void DrawIndexed( const NrPtr<VertexArray>& vertexArray ) = 0;

	public:
		inline static API GetCurrentAPI() { return m_GraphicAPI; }

	private:
		static API m_GraphicAPI;
	};


} // namespace Normal