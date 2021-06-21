#include "Instancing.h"

#include "GLFW/glfw3.h"
#include "VLCore.h"
#include "glad/glad.h"

using namespace Valiance;

int main()
{
    std::unique_ptr<Instancing> app = std::make_unique<Instancing>();
    app->Run();
}

InstancingLayer::InstancingLayer() : show_app_debug(false)
{
    m_Model = glm::mat4(1.0f);
    m_Model = glm::rotate(m_Model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
}

InstancingLayer::~InstancingLayer()
{
}

void InstancingLayer::OnAttach()
{
    struct Vertex
    {
        glm::vec3 Pos;
        glm::vec2 TexCoord;
    };

    Vertex vertices[] = {{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}}, {{0.5f, -0.5f, -0.5f}, {1.0f, 0.0f}},
                         {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},   {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
                         {{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}},  {{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}},

                         {{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},  {{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}},
                         {{0.5f, 0.5f, 0.5f}, {1.0f, 1.0f}},    {{0.5f, 0.5f, 0.5f}, {1.0f, 1.0f}},
                         {{-0.5f, 0.5f, 0.5f}, {0.0f, 1.0f}},   {{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},

                         {{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},   {{-0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
                         {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}}, {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},
                         {{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},  {{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},

                         {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},    {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
                         {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},  {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},
                         {{0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},   {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},

                         {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}}, {{0.5f, -0.5f, -0.5f}, {1.0f, 1.0f}},
                         {{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}},   {{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}},
                         {{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},  {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},

                         {{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}},  {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
                         {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},    {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},
                         {{-0.5f, 0.5f, 0.5f}, {0.0f, 0.0f}},   {{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}}};

    glm::vec3 translations[kNUM_INSTANCES];
    glm::vec3 colors[kNUM_INSTANCES];

    static float v = 0;
    for (int i = 0; i < kNUM_INSTANCES; ++i)
    {
        translations[i] = {
            (float)(i % 500) * 1.5f,
            (i / 500) * 1.5f,
            1.5f * (float)(sin(i * 3.1415 / 10)),
        };
    }

    for (int i = 0; i < kNUM_INSTANCES; ++i)
    {
        colors[i] = glm::vec3(rand() % 255 / 255.0f, rand() % 255 / 255.0f, rand() % 255 / 255.0f);
    }

    vao = std::make_unique<VertexArray>();

    VertexBufferLayout layout{{"aPos", DataType::Float3}, {"aTexCoords", DataType::Float2}};

    VertexBufferLayout layoutTranslations{{"aOffset", DataType::Float3, false, true}};

    VertexBufferLayout layoutColors{{"aColor", DataType::Float3, false, true}};

    vb = std::make_unique<VertexBuffer>(layout, vertices, sizeof(vertices));
    vbTranslations = std::make_unique<VertexBuffer>(layoutTranslations, translations, sizeof(translations));
    vbColors = std::make_unique<VertexBuffer>(layoutColors, colors, sizeof(colors));

    vao->AddBuffer(*vb);
    vao->AddBuffer(*vbTranslations);
    vao->AddBuffer(*vbColors);

    shader = std::make_unique<Shader>("assets/shaders/Instancing.shader");
    shader->Bind();

    texture = std::make_unique<Texture>("assets/textures/image.tga");
    shader->SetUniform1i("ourTexture", 0);

    m_Camera = std::make_unique<Valiance::Utils::PerspectiveCamera>();
}

void InstancingLayer::OnDetach()
{
}

void InstancingLayer::OnImGuiRender()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Debug"))
        {
            if (ImGui::MenuItem("Stats", NULL, &show_app_debug))
            {
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
    if (show_app_debug)
    {
        ImGui::Begin("Stats");
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                    ImGui::GetIO().Framerate);
        ImGui::End();
    }
    // ImGui::ShowDemoWindow();
}

void InstancingLayer::OnUpdate()
{
    vao->Bind();
    texture->Bind();
    m_Camera->ProcessInput(Application::Get().GetWindow().GetNativeWindow());

    m_MVP = m_Camera->GetProjectionMatrix() * m_Camera->GetViewMatrix() * m_Model;
    shader->SetUniformMat4f("u_MVP", m_MVP);

    Renderer::DrawInstanced(*vao, 36, kNUM_INSTANCES);
}
