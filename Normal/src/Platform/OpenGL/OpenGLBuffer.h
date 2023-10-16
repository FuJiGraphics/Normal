#pragma once

#include "Normal/Core/Core.h"
#include "Normal/Renderer/Buffer.h"


namespace Normal {

	int ShaderDataTypeToGLType( const ShaderDataType& type );

	/*___________________________________________________________________________________
	 *   Vertex Buffer
	 *__________________________________________________________________________________*/
	class NORMAL_API OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		explicit OpenGLVertexBuffer( float* vertices, NRuint size );
		virtual ~OpenGLVertexBuffer();

	public:
		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void SetLayout( const Own::Share<BufferLayout>& layout ) override { m_Layout = layout; }
		inline virtual const BufferLayout& GetLayout() const override { return *m_Layout; }

	private:
		NRuint m_RenderID;
		Own::Share<BufferLayout> m_Layout;

		NR_SET_NAME( "OpenGLVertexBuffer" );
	};


	/*___________________________________________________________________________________
	 *    Index Buffer
	 *__________________________________________________________________________________*/
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