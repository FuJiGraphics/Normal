#pragma once

#include <Normal/Core/Core.h>

namespace Normal {

	// These classes just only surve interface functionalities.

	class NORMAL_API VertexBuffer
	{
	protected:
		explicit VertexBuffer() = default;
	public:
		virtual ~VertexBuffer() = default;

	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		static VertexBuffer* Create( float* vertices, NRuint size );
	};



	class NORMAL_API IndexBuffer
	{
	protected:
		explicit IndexBuffer() = default;
	public:
		virtual ~IndexBuffer() = default;

	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual NRuint GetIndexCount() const = 0;

		static IndexBuffer* Create( NRuint* indices, NRuint count );
	};


} // namespace Normal