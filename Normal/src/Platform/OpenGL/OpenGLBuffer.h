#pragma once

#include "Normal/Core/Core.h"
#include "Normal/Renderer/Buffer.h"


namespace Normal {

	class NORMAL_API OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		explicit OpenGLVertexBuffer( float* vertices, NRuint size );
		virtual ~OpenGLVertexBuffer();

	public:
		virtual void Bind() const override;
		virtual void UnBind() const override;

	private:
		NRuint m_RenderID;

		NR_SET_NAME( "OpenGLVertexBuffer" );
	};


	class NORMAL_API OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		explicit OpenGLIndexBuffer( NRuint* indices, NRuint count );
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

	public:
		inline virtual NRuint GetIndexCount() const { return m_IndexCount; }

	private:
		NRuint m_RenderID;
		NRuint m_IndexCount;

		NR_SET_NAME( "OpenGLIndexBuffer" );
	};


} // namespace Normal