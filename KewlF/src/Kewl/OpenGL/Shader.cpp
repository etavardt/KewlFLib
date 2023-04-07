#include "Shader.hpp"

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include <glm/gtc/type_ptr.hpp>
#include <Kewl/Logger.hpp>

#include "OpenGLDebug.hpp"

namespace Kewl
{
    namespace OpenGL
    {
        Shader::Shader() : m_ID(0) {

        }

        Shader::Shader(const std::string& filepath) : m_Filename(filepath), m_ID(0) {
            ShaderProgramSource source = ParseShader(filepath);
            std::cout << "VERTEX SHADER" << std::endl;
            std::cout << source.vertexSource << std::endl;
            std::cout << "FRAGMENT SHADER" << std::endl;
            std::cout << source.fragmentSource << std::endl;
            m_ID = CreateShader(source.vertexSource, source.fragmentSource);
        }

        Shader::~Shader() {
            GLCall(glDeleteProgram(m_ID));
        }

        void Shader::Bind() const {
            GLCall(glUseProgram(m_ID));
        }

        void Shader::Unbind() const {
            GLCall(glUseProgram(0));
        }

        // Set uniforms
        void Shader::SetUniform1i(const std::string& name, int value) {
            GLCall(glUniform1i(GetUniformLocation(name), value));
        }

        void Shader::SetUniform1f(const std::string& name, float value) {
            GLCall(glUniform1f(GetUniformLocation(name), value));
        }

        void Shader::SetUniform2f(const std::string& name, float v0, float v1) {
            GLCall(glUniform2f(GetUniformLocation(name), v0, v1));
        }

        void Shader::SetUniform3f(const std::string& name, float v0, float v1, float v2) {
            GLCall(glUniform3f(GetUniformLocation(name), v0, v1, v2));
        }

        void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
            GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
        }

        void Shader::SetUniform1f(const std::string& name, glm::vec1& value) {
            GLCall(glUniform1f(GetUniformLocation(name), value.x));
        }

        void Shader::SetUniform2f(const std::string& name, glm::vec2& value) {
            GLCall(glUniform2f(GetUniformLocation(name), value.x, value.y));
        }

        void Shader::SetUniform3f(const std::string& name, glm::vec3& value) {
            GLCall(glUniform3f(GetUniformLocation(name), value.x, value.y, value.z));
        }

        void Shader::SetUniform4f(const std::string& name, glm::vec4& value) {
            GLCall(glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.t));
        }

        void Shader::SetUniformMat2f(const std::string& name, const glm::mat2& matrix) {
            GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
        }

        void Shader::SetUniformMat3f(const std::string& name, const glm::mat3& matrix) {
            GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
        }

        void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix) {
            GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
        }

        void Shader::SetUniformMat4fv(const std::string& name, const std::vector<glm::mat4>& matrix) {
            //glUniformMatrix4fv(fShaderUnitSkeletal.uBones, 20, False, @bones20[0]); // Passing 20 matrices
            //glUniformMatrix4fv(jointLoc, 10, GL_FALSE, glm::value_ptr(finalBoneTransforms.at(0)));

            //glUniformMatrix4fv( GetUniformLocation( name ), static_cast<GLsizei>(matrix.size()), GL_FALSE, glm::value_ptr( matrix.data()[0] ) );
            GLCall(glUniformMatrix4fv(GetUniformLocation(name), static_cast<GLsizei>(matrix.size()), GL_FALSE, glm::value_ptr(matrix.data()[0])));
        }


        // The purpous of this function is to keep from hitting a high performace hit call (glGetUniformLocation) by using a cached value.
        // optimized using YouTubeId(@jonasdaverio9369) suggestion.
        int Shader::GetUniformLocation(const std::string& name) {
            auto uniform {m_UniformLocationCache.try_emplace(name, 0)};

            if (uniform.second)
                return (uniform.first->second = glGetUniformLocation(m_ID, name.c_str()));

            return uniform.first->second;
        }

        ShaderProgramSource Shader::ParseShader(const std::string& filepath) {
            std::stringstream ss[2];
            std::ifstream stream(filepath);

            if (stream.is_open())
            {

                enum class ShaderType
                {
                    NONE = -1,
                    VERTEX = 0,
                    FRAGMENT = 1
                };

                ShaderType type = ShaderType::NONE;

                std::string line;
                while (getline(stream, line))
                {
                    if (line.find("#shader") != std::string::npos)
                    {
                        if (line.find("vertex") != std::string::npos)
                        {
                            type = ShaderType::VERTEX;
                        }
                        else if (line.find("fragment") != std::string::npos)
                        {
                            type = ShaderType::FRAGMENT;
                        }
                    }
                    else
                    {
                        ss[(int)type] << line << "\n";
                    }
                }
            }
            else
            {
                LOG(ERROR) << "Unable to open file(" << std::quoted(filepath) << ")" << std::endl;
            }

            return {ss[0].str(), ss[1].str()};
        }

        int Shader::CompileShader(unsigned int type, const std::string& source) {
            //std::assert(source);
            GLuint id = glCreateShader(type);
            const char* src = source.c_str();
            GLCall(glShaderSource(id, 1, &src, nullptr));
            GLCall(glCompileShader(id));

            //Syntax checking and Error handling
            GLint result;
            GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

            GLint length;
            if (result == GL_FALSE)
            {
                GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
                char* message = (char*)alloca(length * sizeof(char));

                GLCall(glGetShaderInfoLog(id, length, &length, message));
                std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
                std::cout << message << std::endl;

                std::cout << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << " SHADER" << std::endl;
                std::cout << source << std::endl;

                GLCall(glDeleteShader(id));
                return 0;
            }

            return id;
        }

        unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
            GLuint progId = glCreateProgram();
            GLuint vshaderId = CompileShader(GL_VERTEX_SHADER, vertexShader);
            GLuint fshaderId = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

            GLCall(glAttachShader(progId, vshaderId));
            GLCall(glAttachShader(progId, fshaderId));
            GLCall(glLinkProgram(progId));
            GLCall(glValidateProgram(progId));

            //GLCall(glDetachShader(progId, vshaderId));
            //GLCall(glDetachShader(progId, fshaderId));

            GLCall(glDeleteShader(vshaderId));
            GLCall(glDeleteShader(fshaderId));

            return progId;
        }
    } // namespace OpenGL
} // namespace Kewl