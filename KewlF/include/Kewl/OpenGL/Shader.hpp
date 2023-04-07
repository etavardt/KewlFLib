#pragma once

#include <string>
#include <unordered_map>

#include <glm/glm.hpp>

namespace Kewl
{
	namespace OpenGL
	{
		struct ShaderProgramSource
		{
			std::string vertexSource;
			std::string fragmentSource;
		};

		class Shader
		{
		private:
			unsigned int m_ID; //GLuint
			std::unordered_map<std::string, int> m_UniformLocationCache;
			std::string m_Filename;

		public:
			Shader();
			Shader(const std::string& filepath);
			~Shader();

			void Bind() const;
			void Unbind() const;

			inline unsigned int GetID() const {
				return m_ID;
			}

			// Set uniforms
			void SetUniform1i(const std::string& name, int value);
			void SetUniform1f(const std::string& name, float value);
			void SetUniform2f(const std::string& name, float v0, float v1);
			void SetUniform3f(const std::string& name, float v0, float v1, float v2);
			void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
			void SetUniform1f(const std::string& name, glm::vec1& value);
			void SetUniform2f(const std::string& name, glm::vec2& value);
			void SetUniform3f(const std::string& name, glm::vec3& value);
			void SetUniform4f(const std::string& name, glm::vec4& value);

			void SetUniformMat2f(const std::string& name, const glm::mat2& matrix);
			void SetUniformMat3f(const std::string& name, const glm::mat3& matrix);
			void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

			void SetUniformMat4fv(const std::string& name, const std::vector<glm::mat4>& matrix);

		private:
			int GetUniformLocation(const std::string& name);

			ShaderProgramSource ParseShader(const std::string& filepath);
			int CompileShader(unsigned int type, const std::string& source);
			unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
		};
	} // namespace OpenGL
} // namespace Kewl