#pragma once

#include <memory>
#include "Window.h"

namespace Valiance
{
	class Application
	{
	public:
		Application();
		~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running;
	};
}