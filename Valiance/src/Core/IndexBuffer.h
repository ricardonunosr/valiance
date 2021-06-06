#pragma once

#include <cstdint>

namespace Valiance
{
    class IndexBuffer
    {
      public:
        IndexBuffer(const void *data, unsigned int count);
        ~IndexBuffer();

        void Bind();
        void Unbind();

        inline unsigned int GetCount() const
        {
            return m_Count;
        }

      private:
        uint32_t m_RendererID;
        unsigned int m_Count;
    };
} // namespace Valiance
