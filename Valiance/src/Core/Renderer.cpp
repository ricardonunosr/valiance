#include "Renderer.h"

#include "glad/glad.h"

namespace Valiance
{

    void Renderer::SetClearColor(float v0, float v1, float v2, float v3)
    {
        glClearColor(v0, v1, v2, v3);
    }

    void Renderer::DrawTriangles(const VertexArray &vertexArray, const uint32_t count)
    {
        vertexArray.Bind();
        glDrawArrays(GL_TRIANGLES, 0, count);
    }

    void Renderer::DrawIndexed(const VertexArray &vertexArray, const IndexBuffer &indexBuffer)
    {
        vertexArray.Bind();
        indexBuffer.Bind();
        glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, 0);
    }

    void Renderer::DrawInstanced(const VertexArray &vertexArray, const uint32_t count, const uint32_t numInstances)
    {
        vertexArray.Bind();
        glDrawArraysInstanced(GL_TRIANGLES, 0, count, numInstances);
    }

} // namespace Valiance