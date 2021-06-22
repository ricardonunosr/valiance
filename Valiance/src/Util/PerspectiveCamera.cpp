#include "PerspectiveCamera.h"

#include "glm/gtc/matrix_transform.hpp"

namespace Valiance::Utils
{
    PerspectiveCamera::PerspectiveCamera()
    {
        m_Projection = glm::perspective(glm::radians(95.0f), 1280.0f / 720.0f, 0.1f, 1000.0f);
        m_CameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
        m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        m_CameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

        m_View = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);
    }

    PerspectiveCamera::~PerspectiveCamera()
    {
    }

    void PerspectiveCamera::ProcessInput(GLFWwindow *window)
    {
        const float cameraSpeed = 0.05f;
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            m_CameraPos += cameraSpeed * m_CameraFront;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            m_CameraPos -= cameraSpeed * m_CameraFront;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            m_CameraPos -= glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            m_CameraPos += glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * cameraSpeed;

        RecalculateView();
    }

    void PerspectiveCamera::RecalculateView()
    {
        m_View = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);
    }

} // namespace Valiance::Utils