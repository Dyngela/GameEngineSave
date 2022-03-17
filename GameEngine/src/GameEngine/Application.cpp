#include "nepch.h"
#include "Application.h"
#include "Log.h"

#include <glad/glad.h>

namespace NE {

	  Application* Application::s_Instance = nullptr;

	  Application::Application()
	  {
			s_Instance = this;

			m_Window = std::unique_ptr<Window>(Window::Create());
			m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

			unsigned int id;
			glGenVertexArrays(1, &id);
	  }

	  Application::~Application()
	  {
	  }



	  void Application::Run()
	  {
			while (m_Running)
			{
				  glClearColor(1, 0, 1, 1);
				  glClear(GL_COLOR_BUFFER_BIT);

				  for (Layer* layer : m_LayerStack)
				  {
						layer->OnUpdate();
				  }
				  m_Window->OnUpdate();
			}
	  }

	  void Application::PushLayer(Layer* layer)
	  {
			m_LayerStack.PushLayer(layer);
			layer->OnAttach();
	  }

	  void Application::PushOverlay(Layer* overlay)
	  {
			m_LayerStack.PushOverlay(overlay);
			overlay->OnAttach();

	  }

	  void Application::OnEvent(Event& e)
	  {
			EventDispatcher dispatcher(e);
			dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

			NE_CORE_INFO("{0}", e);

			for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
			{
				  (*--it)->OnEvent(e);
				  if (e.Handled)
						break;
			}
	  }

	  bool Application::OnWindowClose(WindowCloseEvent& e)
	  {
			m_Running = false;
			return true;
	  }

}


