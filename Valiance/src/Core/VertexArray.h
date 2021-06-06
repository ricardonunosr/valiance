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
        void Bind();
        void Unbind();
        void AddBuffer(VertexBuffer &vb, const VertexBufferLayout &layout);

      private:
        unsigned int m_RendererID;
    };
} // namespace Valiance
