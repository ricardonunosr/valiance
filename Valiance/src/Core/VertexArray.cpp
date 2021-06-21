#include "VertexArray.h"
#include "glad/glad.h"

namespace Valiance
{
    static GLenum ShaderDataTypeToOpenGLBaseType(DataType type)
    {
        switch (type)
        {
        case DataType::Float:
            return GL_FLOAT;
        case DataType::Float2:
            return GL_FLOAT;
        case DataType::Float3:
            return GL_FLOAT;
        case DataType::Float4:
            return GL_FLOAT;
        case DataType::Mat3:
            return GL_FLOAT;
        case DataType::Mat4:
            return GL_FLOAT;
        case DataType::Int:
            return GL_INT;
        case DataType::Int2:
            return GL_INT;
        case DataType::Int3:
            return GL_INT;
        case DataType::Int4:
            return GL_INT;
        case DataType::Bool:
            return GL_BOOL;
        }

        return 0;
    }

    VertexArray::VertexArray() : m_RendererID(0), m_EnableAtribs(0)
    {
        glCreateVertexArrays(1, &m_RendererID);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(m_RendererID);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void VertexArray::AddBuffer(VertexBuffer &vb)
    {
        Bind();
        vb.Bind();
        const auto &elements = vb.GetLayout().GetElements();
        for (unsigned int i = 0; i < elements.size(); i++)
        {
            const auto &element = elements[i];
            glEnableVertexAttribArray(m_EnableAtribs);
            glVertexAttribPointer(m_EnableAtribs, element.GetComponentCount(),
                                  ShaderDataTypeToOpenGLBaseType(element.type), element.normalized,
                                  vb.GetLayout().GetStride(), (const void *)element.offset);

            if (element.instanced)
                glVertexAttribDivisor(m_EnableAtribs, 1);
            m_EnableAtribs++;
        }
    }

} // namespace Valiance