#include "Application.h"

#include "glad/glad.h"

#include <memory>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Valiance
{

	Application::Application()
	{
		m_Window = std::make_unique<Window>();

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(m_Window->GetWindow(), true);
		ImGui_ImplOpenGL3_Init((char*)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));

		m_Running = true;
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		float m_ClearColor[4]{ 0.8f, 0.4f, 0.2f, 1.0f };

		while (m_Running)
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			glBegin(GL_TRIANGLES);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.5f, -0.5f);
			glVertex2f(0, 0.5f);
			glEnd();

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			ImGui::Begin("Test");
			ImGui::ColorEdit4("Clear Color", m_ClearColor);
			ImGui::End();

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			m_Window->OnUpdate();
		}
	}

}