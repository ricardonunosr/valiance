#include "Application.h"

#include <iostream>
#include <memory>

#include "IndexBuffer.h"
#include "Shader.h"
#include "Util/OpenGLDebug.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "glad/glad.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Valiance
{
    // Singleton
    Application *Application::s_Instance = nullptr;

    Application::Application()
    {
        s_Instance = this;
        m_Window = std::make_unique<Window>();

        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        glEnable(GL_DEPTH_TEST);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void)io;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(m_Window->GetNativeWindow(), true);
        ImGui_ImplOpenGL3_Init((char *)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));

        std::cout << "Using GL Version: " << glGetString(GL_VERSION) << std::endl;

        Valiance::Utils::EnableOpenGLDebugging();
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (m_Window->IsActive())
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            for (Layer *layer : m_LayerStack)
                layer->OnUpdate();

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            for (Layer *layer : m_LayerStack)
                layer->OnImGuiRender();

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            m_Window->OnUpdate();
        }
    }

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
    }

} // namespace Valiance