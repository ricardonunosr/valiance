#pragma once

#include <memory>
#include "GLFW/glfw3.h"

namespace Valiance
{
	class Window
	{
		public:
			Window();
			~Window();
			void Init();
			void OnUpdate();
			GLFWwindow* GetWindow() const { return m_Window; }
		private:
			float m_Width;
			float m_Height;
			GLFWwindow* m_Window;
	};

}