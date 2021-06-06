#include "Shader.h"
#include "glad/glad.h"
#include <fstream>
#include <sstream>
#include <iostream>

namespace Valiance
{

	Shader::Shader(const std::string& filePath)
	{
		ShaderProgramSource source = ParseShader(filePath);
		m_RendererID = CreateShader(source.vertexSource,source.fragmentSource);
	}

	Shader::Shader(const std::string& vertexSouce, const std::string& fragSource)
	{
		//TODO
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}

	void Shader::Bind()
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	Valiance::ShaderProgramSource Shader::ParseShader(const std::string& filePath)
	{
		std::string result;
		std::ifstream stream(filePath);
		
		enum class ShaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		std::string line;
		std::stringstream ss[2];
		ShaderType type = ShaderType::NONE;
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
				ss[(int)type] << line << '\n';
			}
		}

		return { ss[0].str(),ss[1].str() };
	}

	unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (!result)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader!" << std::endl;
			std::cout << message << std::endl;

			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	unsigned int Shader::CreateShader(const std::string& vertexSource, const std::string& fragmentSource)
	{
		unsigned int program = glCreateProgram();
		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexSource);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}

}