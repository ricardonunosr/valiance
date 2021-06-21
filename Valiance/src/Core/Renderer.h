#pragma once

#include "IndexBuffer.h"
#include "VertexArray.h"

namespace Valiance
{
    class Renderer
    {
      public:
        static void SetClearColor(float v0, float v1, float v2, float v3);

        static void DrawTriangles(const VertexArray &vertexArray, const uint32_t count);
        static void DrawIndexed(const VertexArray &vertexArray, const IndexBuffer &indexBuffer);
        static void DrawInstanced(const VertexArray &vertexArray, const uint32_t count, const uint32_t numInstances);

      private:
    };
} // namespace Valiance
