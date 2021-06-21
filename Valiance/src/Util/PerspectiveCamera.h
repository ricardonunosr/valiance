#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "GLFW/glfw3.h"

namespace Valiance::Utils
{
    class PerspectiveCamera
    {
      public:
        PerspectiveCamera();
        ~PerspectiveCamera();

        void ProcessInput(GLFWwindow *window);
        
        glm::mat4 GetViewMatrix() const
        {
            return m_View;
        }

        glm::mat4 GetProjectionMatrix() const
        {
            return m_Projection;
        }

      private:
        glm::mat4 m_Projection;
        glm::mat4 m_View;
        glm::vec3 m_CameraPos;
        glm::vec3 m_CameraFront;
        glm::vec3 m_CameraUp;
        void RecalculateView();
    };
} // namespace Valiance
