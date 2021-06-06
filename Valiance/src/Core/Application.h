#pragma once

#include <memory>
#include "Window.h"
#include "LayerStack.h"

namespace Valiance
{
	class Application
	{
	public:
		Application();
		~Application();
		
		void Run();
		void PushLayer(Layer* layer);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running;
		LayerStack m_LayerStack;
	};
}