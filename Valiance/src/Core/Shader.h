#pragma once

#include <string>

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

      private:
        unsigned int m_RendererID;
    };
} // namespace Valiance
