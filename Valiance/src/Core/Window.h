#pragma once

#include "GLFW/glfw3.h"
#include <memory>

namespace Valiance
{
    class Window
    {
      public:
        Window();
        ~Window();
        void Init();
        void OnUpdate();
        GLFWwindow *GetNativeWindow() const
        {
            return m_Window;
        }

        inline bool IsActive() const
        {
            return m_IsActive;
        }

      private:
        float m_Width;
        float m_Height;
        GLFWwindow *m_Window;
        bool m_IsActive;
    };
} // namespace Valiance