#pragma once

#include <Normal/Core/Core.h>
#include <string>

namespace Normal {

	class NORMAL_API Texture
	{
	public:
		virtual ~Texture() = default;

		virtual void Bind() = 0;

		inline virtual NRuint GetWidth() const = 0;
		inline virtual NRuint GetHeight() const = 0;
	};


	class NORMAL_API Texture2D : public Texture
	{
	public:
		virtual ~Texture2D() = default;

		virtual void Bind() = 0;
		virtual void SetData( void* data, NRuint size ) = 0;

		inline virtual NRuint GetWidth() const = 0;
		inline virtual NRuint GetHeight() const = 0;

		static Own::Share<Texture2D> Create( NRint width, NRint height );
		static Own::Share<Texture2D> Create( const std::string& path );
	};

} // namespace Normal
