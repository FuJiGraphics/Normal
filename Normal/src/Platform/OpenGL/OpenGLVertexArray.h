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

		virtual void AddVertexBuffer( const Own::Share<VertexBuffer>& vertexBuffer ) override;
		virtual void SetIndexBuffer( const Own::Share<IndexBuffer>& indexBuffer ) override;

		virtual const Own::Share<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }

	private:
		std::vector<Own::Share<VertexBuffer>> m_VertexBuffers;
		Own::Share<IndexBuffer> m_IndexBuffer;

		NRuint m_RenderID;
		NR_SET_NAME( "OpenGLVertexArray" );
	};



} // namespace Normal