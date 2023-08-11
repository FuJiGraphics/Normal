#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Renderer/VertexArray.h>

#include <vector>
#include <memory>

namespace Normal {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		explicit OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

	public:
		virtual void Bind() const override;
		virtual void UnBind() const  override;

		virtual void AddVertexBuffer( const std::shared_ptr<VertexBuffer>& vertexBuffer ) override;
		virtual void SetIndexBuffer( const std::shared_ptr<IndexBuffer>& indexBuffer ) override;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }

	private:
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;

		NRuint m_RenderID;
		NR_SET_NAME( "OpenGLVertexArray" );
	};



} // namespace Normal