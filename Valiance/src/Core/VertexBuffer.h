#pragma once
#include "VertexBufferLayout.h"

namespace Valiance
{
    class VertexBuffer
    {
      public:
        VertexBuffer(const VertexBufferLayout& layout, const void *data, unsigned int size);
        ~VertexBuffer();
        void Bind() const;
        void Unbind() const;

        inline unsigned int GetID() const
        {
            return m_RendererID;
        }

        inline VertexBufferLayout GetLayout() const
        {
            return m_Layout;
        }

      private:
        unsigned int m_RendererID;
        VertexBufferLayout m_Layout;
    };
} // namespace Valiance
