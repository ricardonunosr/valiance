#pragma once

#include "LayerStack.h"
#include "Window.h"
#include <memory>

namespace Valiance
{
    class Application
    {
      public:
        Application();
        ~Application();

        void Run();
        void PushLayer(Layer *layer);

        static Application &Get()
        {
            return *s_Instance;
        }

        Window& GetWindow()
        {
            return *m_Window;
        }

      private:
        static Application *s_Instance;
        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;
    };
} // namespace Valiance