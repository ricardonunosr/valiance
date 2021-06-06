#pragma once

#include <vector>
#include "glad/glad.h"

namespace Valiance
{
	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned char normalized;
			
		//Done because can be different sizes in various implementations
		static unsigned int GetTypeSize(unsigned int type)
		{
			switch (type)
			{
			case GL_FLOAT: return 4;
			case GL_UNSIGNED_INT: return 4;
			case GL_UNSIGNED_BYTE:return 1;
			}

			return 0;
		}
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout()
			:m_Stride(0){}
		
		template<typename T>
		void Push(unsigned int count)
		{
			static_assert(false);
		}

		template<>
		void Push<float>(unsigned int count)
		{
			m_Elements.push_back({GL_FLOAT,count,GL_FALSE});
			m_Stride += count * VertexBufferElement::GetTypeSize(GL_FLOAT);
		}
	
		inline unsigned int GetStride() const { return m_Stride; }
		inline std::vector<VertexBufferElement> GetElements() const { return m_Elements; }

	private:
		std::vector<VertexBufferElement> m_Elements;
		unsigned int m_Stride;
	};
}