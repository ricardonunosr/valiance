#include "VertexArray.h"

#include "glad/glad.h"

namespace Valiance
{

	VertexArray::VertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1,&m_RendererID);
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(m_RendererID);
	}

	void VertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

	void VertexArray::AddBuffer( VertexBuffer& vb, const VertexBufferLayout& layout)
	{
		Bind();
		vb.Bind();
		const auto& elements=layout.GetElements();
		unsigned int offset = 0;
		for (unsigned int i= 0; i<elements.size();i++)
		{
			const auto& element = elements[i];
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, element.count,element.type, element.normalized,layout.GetStride(),(const void*) offset);
			offset += element.count * VertexBufferElement::GetTypeSize(element.type);
		}
		
		
	}

}