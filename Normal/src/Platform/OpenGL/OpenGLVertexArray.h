#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Renderer/VertexArray.h>
#include <Normal/Core/NrPointer.h>

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

		virtual void AddVertexBuffer( const NrPtr<VertexBuffer>& vertexBuffer ) override;
		virtual void SetIndexBuffer( const NrPtr<IndexBuffer>& indexBuffer ) override;

		virtual const std::vector<NrPtr<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
		virtual const NrPtr<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }

	private:
		std::vector<NrPtr<VertexBuffer>> m_VertexBuffers;
		NrPtr<IndexBuffer> m_IndexBuffer;

		NRuint m_RenderID;
		NR_SET_NAME( "OpenGLVertexArray" );
	};



} // namespace Normal