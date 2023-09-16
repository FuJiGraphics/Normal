#pragma once

#include <Normal/Core/Core.h>
#include <memory>

namespace Normal {

	class VertexBuffer;
	class IndexBuffer;

	class NORMAL_API VertexArray
	{
	protected:
		explicit VertexArray() = default;
	public:
		virtual ~VertexArray() = default;

	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void AddVertexBuffer( const NrPtr<VertexBuffer>& vertexBuffer ) = 0;
		virtual void SetIndexBuffer( const NrPtr<IndexBuffer>& indexBuffer ) = 0;

		virtual const std::vector<NrPtr<VertexBuffer>>& GetVertexBuffers() const = 0;
		virtual const NrPtr<IndexBuffer>& GetIndexBuffer() const = 0;

		static VertexArray* Create();
	};

}  // namespace Normal


