#include "Sandbox.h"

#include "glad/glad.h"
#include <memory>

using namespace Valiance;

int main()
{
    std::unique_ptr<Sandbox> app = std::make_unique<Sandbox>();
    app->Run();
}

SandboxLayer::SandboxLayer()
{
}

SandboxLayer::~SandboxLayer()
{
}

void SandboxLayer::OnAttach()
{
    float vertices[] = {-0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  -1.0f, 0.5f,  -0.5f, -0.5f, 0.0f,  0.0f,  -1.0f,
                        0.5f,  0.5f,  -0.5f, 0.0f,  0.0f,  -1.0f, 0.5f,  0.5f,  -0.5f, 0.0f,  0.0f,  -1.0f,
                        -0.5f, 0.5f,  -0.5f, 0.0f,  0.0f,  -1.0f, -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  -1.0f,

                        -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,  0.5f,  -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,
                        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
                        -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,

                        -0.5f, 0.5f,  0.5f,  -1.0f, 0.0f,  0.0f,  -0.5f, 0.5f,  -0.5f, -1.0f, 0.0f,  0.0f,
                        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f,  0.0f,  -0.5f, -0.5f, -0.5f, -1.0f, 0.0f,  0.0f,
                        -0.5f, -0.5f, 0.5f,  -1.0f, 0.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  -1.0f, 0.0f,  0.0f,

                        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.5f,  0.5f,  -0.5f, 1.0f,  0.0f,  0.0f,
                        0.5f,  -0.5f, -0.5f, 1.0f,  0.0f,  0.0f,  0.5f,  -0.5f, -0.5f, 1.0f,  0.0f,  0.0f,
                        0.5f,  -0.5f, 0.5f,  1.0f,  0.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

                        -0.5f, -0.5f, -0.5f, 0.0f,  -1.0f, 0.0f,  0.5f,  -0.5f, -0.5f, 0.0f,  -1.0f, 0.0f,
                        0.5f,  -0.5f, 0.5f,  0.0f,  -1.0f, 0.0f,  0.5f,  -0.5f, 0.5f,  0.0f,  -1.0f, 0.0f,
                        -0.5f, -0.5f, 0.5f,  0.0f,  -1.0f, 0.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  -1.0f, 0.0f,

                        -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,
                        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
                        -0.5f, 0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f};

    m_VAOCube = std::make_unique<VertexArray>();
    m_VAOLight = std::make_unique<VertexArray>();

    VertexBufferLayout layout{{"aPos", DataType::Float3}, {"aNormal", DataType::Float3}};

    m_Vb = std::make_unique<VertexBuffer>(layout, vertices, sizeof(vertices));

    m_VAOCube->AddBuffer(*m_Vb);
    m_VAOLight->AddBuffer(*m_Vb);

    m_ShaderLightCube = std::make_unique<Shader>("assets/shaders/LightCube.shader");
    m_ShaderLighting = std::make_unique<Shader>("assets/shaders/Lighting.shader");

    m_Camera = std::make_unique<Valiance::Utils::PerspectiveCamera>();
}

void SandboxLayer::OnDetach()
{
}

void SandboxLayer::OnImGuiRender()
{
}

void SandboxLayer::OnUpdate()
{
    m_Camera->ProcessInput(Application::Get().GetWindow().GetNativeWindow());

   

    glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
    glm::mat4 m_Model = glm::mat4(1.0f);
    glm::mat4 m_MVP = m_Camera->GetProjectionMatrix() * m_Camera->GetViewMatrix() * m_Model;

    m_ShaderLighting->Bind();
    glm::vec3 cameraPos=m_Camera->GetCameraPosition();
    m_ShaderLighting->SetUniform3f("u_ViewPos", cameraPos.x, cameraPos.y, cameraPos.z);
    m_ShaderLighting->SetUniform3f("u_LightPos", 1.2f, 1.0f, 2.0f);
    m_ShaderLighting->SetUniformMat4f("u_model", m_Model);
    m_ShaderLighting->SetUniform3f("u_LightColor", 1.0f, 1.0f, 1.0f);
    m_ShaderLighting->SetUniform3f("u_ObjectColor", 1.0f, 0.5f, 0.31f);
    m_ShaderLighting->SetUniformMat4f("u_MVP", m_MVP);
    Renderer::DrawTriangles(*m_VAOCube, 36);

    m_ShaderLightCube->Bind();

    glm::mat4 m_Model1 = glm::mat4(1.0f);
    m_Model1 = glm::translate(m_Model1, lightPos);
    m_Model1 = glm::scale(m_Model1, glm::vec3(0.2f));
    glm::mat4 m_MVP1 = m_Camera->GetProjectionMatrix() * m_Camera->GetViewMatrix() * m_Model1;

    m_ShaderLightCube->SetUniformMat4f("u_MVP", m_MVP1);
    Renderer::DrawTriangles(*m_VAOLight, 36);
}
