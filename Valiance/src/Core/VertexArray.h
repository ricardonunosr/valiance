#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace Valiance
{
    class VertexArray
    {
      public:
        VertexArray();
        ~VertexArray();
        void Bind() const;
        void Unbind() const;
        void AddBuffer(VertexBuffer &vb);

      private:
        unsigned int m_RendererID;
        unsigned int m_EnableAtribs;
    };
} // namespace Valiance
