#include "Instancing.h"

#include "Core/Application.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

using namespace Valiance;

int main()
{
    std::unique_ptr<Instancing> app = std::make_unique<Instancing>();
    app->Run();
}

InstancingLayer::InstancingLayer()
{
    m_RotationVector = glm::vec3(1.0f, 0.3f, 0.5f);

    m_Proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    m_View = glm::mat4(1.0f);
    m_View = glm::translate(m_View, glm::vec3(0.0f, 0.0f, -3.0f)); 
    m_Model = glm::mat4(1.0f);
    m_Model = glm::rotate(m_Model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 
    m_Radians = 0.0f;

    m_MVP = m_Proj * m_View * m_Model;
}

InstancingLayer::~InstancingLayer()
{
}

void InstancingLayer::OnAttach()
{

    //float vertices[] = {
    //    //Pos              //Color           //Texture 
    //    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    //    -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
    //    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
    //    -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,

    //    0.5f,  -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    //    0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
    //    0.5f,  0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
    //    0.5f,  -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f
    //};

  /*  unsigned int indices[] = {
        0, 1, 2, 0, 2, 3,

        1, 5, 6, 1, 2, 6,

        4, 5, 7, 5, 7, 6,

        0, 4, 3, 4, 3, 7,

        2,7,6,2,3,7,

        1,5,4,1,6,4

    };*/

    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 
        0.5f,  -0.5f, -0.5f, 1.0f, 0.0f, 
        0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
        0.5f,  0.5f,  -0.5f, 1.0f, 1.0f, 
        -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f, 
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 
        0.5f,  -0.5f, 0.5f,  1.0f, 0.0f, 
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 
        -0.5f, 0.5f,  0.5f,  0.0f, 1.0f, 
        -0.5f, -0.5f, 0.5f,  0.0f, 0.0f,

        -0.5f, 0.5f,  0.5f,  1.0f, 0.0f, 
        -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f, 
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 
        -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 
        -0.5f, 0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 
        0.5f,  0.5f,  -0.5f, 1.0f, 1.0f, 
        0.5f,  -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f,  -0.5f, -0.5f, 0.0f, 1.0f, 
        0.5f,  -0.5f, 0.5f,  0.0f, 0.0f, 
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 
        0.5f,  -0.5f, -0.5f, 1.0f, 1.0f, 
        0.5f,  -0.5f, 0.5f,  1.0f, 0.0f,
        0.5f,  -0.5f, 0.5f,  1.0f, 0.0f, 
        -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

        -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f, 
        0.5f,  0.5f,  -0.5f, 1.0f, 1.0f, 
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 
        -0.5f, 0.5f,  0.5f,  0.0f, 0.0f, 
        -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f
    };

    vao = std::make_unique<VertexArray>();
    vb = std::make_unique<VertexBuffer>(vertices, 180 * sizeof(float));
    VertexBufferLayout layout;
    layout.Push<float>(3);
    //layout.Push<float>(3);
    layout.Push<float>(2);

  /*  ib = std::make_unique<IndexBuffer>(indices, 36);*/

    vao->AddBuffer(*vb, layout);

    shader = std::make_unique<Shader>("assets/shaders/Instancing.shader");

    //ib->Bind();
    shader->Bind();

    texture = std::make_unique<Texture>("assets/textures/minecraft-dirt-texture.jpg");
    shader->SetUniform1i("ourTexture", 0);

    m_Camera = std::make_unique<Valiance::Utils::PerspectiveCamera>();
}

void InstancingLayer::OnDetach()
{
}

void InstancingLayer::OnImGuiRender()
{
    ImGui::SliderFloat3("Rotation Vector", &m_RotationVector.x, 0.01, 1);
    ImGui::SliderFloat("Rotation Speed", &m_Radians, 0, 5);
}

void InstancingLayer::OnUpdate()
{
    texture->Bind();

    //m_Model = glm::translate(glm::mat4(1.0f), m_Translation);
    m_Model = glm::rotate(m_Model, glm::radians(m_Radians), m_RotationVector);  
    m_Camera->ProcessInput(Application::Get().GetWindow().GetNativeWindow());

    m_MVP = m_Proj * m_Camera->GetViewMatrix() * m_Model;
    shader->SetUniformMat4f("u_MVP", m_MVP);
    

    glDrawArrays(GL_TRIANGLES,0,36);
    //glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, 0);
}
