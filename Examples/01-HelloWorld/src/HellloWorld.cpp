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

    VertexBufferLayout layout{{"aPos", DataType::Float3}, {"aColor", DataType::Float3}};

    vb = std::make_unique<VertexBuffer>(layout, vertices, 18 * sizeof(float));

    ib = std::make_unique<IndexBuffer>(indices, 6);

    vao->AddBuffer(*vb);

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
    Renderer::SetClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]);

    Renderer::DrawIndexed(*vao, *ib);
}
