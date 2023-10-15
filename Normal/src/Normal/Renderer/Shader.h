#pragma once

#include <Normal/Core/Core.h>
#include <unordered_map>
#include <string>

namespace Normal {

	struct ShaderPaths
	{
		std::string VertPath;
		std::string FragPath;
	};

	class NORMAL_API Shader
	{
	protected:
		explicit Shader() = default;
	public:
		virtual ~Shader() = default;

	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetInt( const std::string& name, const NRint& int1 ) = 0;
		virtual void SetFloat4( const std::string& name, const glm::vec4& float4 ) = 0;
		virtual void SetMat4( const std::string& name, const glm::mat4& mat4 ) = 0;

		static Shader* Create( const ShaderPaths& paths );
		static Shader* Create( const std::string& vertexSrc, const std::string& fragmentSrc );
	};

	class NORMAL_API ShaderManager
	{
	public:
		ShaderManager() = default;
		~ShaderManager() = default;

		void Add( const std::string& name, Shader* shader );
		bool Exist( const std::string& name ) const;

		inline Own::Share<Shader>& Get( const std::string name ) { 
			return m_Shaders[name];
		}

	private:
		std::unordered_map< std::string, Own::Share<Shader> > m_Shaders;
	};
} // namespace Normal