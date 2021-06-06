#include "IndexBuffer.h"

#include "glad/glad.h"

namespace Valiance
{

	IndexBuffer::IndexBuffer(const void* data,unsigned int count)
		: m_Count(count)
	{
		glCreateBuffers(1,&m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1,&m_RendererID);
	}

	void IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_RendererID);
	}

	void IndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}