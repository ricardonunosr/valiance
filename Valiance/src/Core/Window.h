#pragma once

#include "GLFW/glfw3.h"
#include <memory>
#include <string>

namespace Valiance
{
    struct WindowProps
    {
        std::string title;
        uint32_t width;
        uint32_t height;

        WindowProps(const std::string &title = "Valiance", uint32_t width = 1280, uint32_t height = 720)
            : title(title), width(width), height(height)
        {
        }
    };

    class Window
    {
      public:
        Window(const WindowProps &props = WindowProps());
        ~Window();
        void Init(const WindowProps &props);
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