#pragma once

#include <string>
#include <unordered_map>

#include "glm/glm.hpp"

namespace Valiance
{
    struct ShaderProgramSource
    {
        std::string vertexSource;
        std::string fragmentSource;
    };

    class Shader
    {
      public:
        Shader(const std::string &filePath);
        Shader(const std::string &vertexSouce, const std::string &fragSource);
        ~Shader();

        void Bind();
        void Unbind();

        ShaderProgramSource ParseShader(const std::string &filePath);
        unsigned int CompileShader(unsigned int type, const std::string &source);
        unsigned int CreateShader(const std::string &vertexSource, const std::string &fragmentSource);

        void SetUniform1i(const std::string &name, int value);
        void SetUniform2f(const std::string &name, int v0, int v1);
        void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3);
        void SetUniformMat4f(const std::string &name, const glm::mat4 &matrix);

      private:
        unsigned int m_RendererID;
        std::unordered_map<std::string, int> m_UniformCache;

      private:
        int GetUniformLocation(const std::string &name);
    };
} // namespace Valiance
