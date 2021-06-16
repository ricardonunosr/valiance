#include "HelloWorld.h"

#include "glad/glad.h"

using namespace Valiance;

int main()
{
    std::unique_ptr<HelloWorld> app = std::make_unique<HelloWorld>();
    app->Run();
}

HelloWorldLayer::HelloWorldLayer() : m_ClearColor{0.0f, 0.0f, 0.0f, 1.0f}
{
}

HelloWorldLayer::~HelloWorldLayer()
{
}

void HelloWorldLayer::OnAttach()
{
    float vertices[] = {
        // positions         // colors
        0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
        0.0f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f  // top
    };

    unsigned int indices[] = {
        0,
        1,
        2,
    };

    vao = std::make_unique<VertexArray>();
    vb = std::make_unique<VertexBuffer>(vertices, 18 * sizeof(float));
    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(3);

    ib = std::make_unique<IndexBuffer>(indices, 6);

    vao->AddBuffer(*vb, layout);

    shader = std::make_unique<Shader>("assets/shaders/Basic.shader");

    ib->Bind();
    shader->Bind();
}

void HelloWorldLayer::OnDetach()
{
}

void HelloWorldLayer::OnImGuiRender()
{
    ImGui::ColorEdit4("ClearColor", m_ClearColor);
}

void HelloWorldLayer::OnUpdate()
{
    glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]);

    glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, 0);
}
