#include "nepch.h"
#include "Application.h"
#include "Log.h"

#include <glad/glad.h>

#include "Input.h"

namespace NE {

	  Application* Application::s_Instance = nullptr;

	  Application::Application()
	  {
			s_Instance = this;

			m_Window = std::unique_ptr<Window>(Window::Create());
			m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

			unsigned int id;
			glGenVertexArrays(1, &id);

			m_ImGuiLayer = new ImGuiLayer();
			PushOverlay(m_ImGuiLayer);

			//Vertex array
			//Vertex Buffer
			//Index Buffer
			//Shader

			glGenVertexArrays(1, &m_VertexArray);
			glBindVertexArray(m_VertexArray);

			

			float vertices[3 * 3] = {
				  -0.5f, -0.5f,  0.0f,
				   0.5f,  -0.5,  0.0f,
				   0.0f,  0.5f,  0.0f
			};

			m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

			unsigned int indices[3] = { 0, 1, 2 };
			//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			m_IndexBuffer.reset(IndexBuffer::Create(indices, std::size(indices)));

			std::string vertexSrc = R"(
				  #version 330 core
					
				  layout(location = 0) in vec3 a_Position;						

				  void main() 
				  {
						gl_Position = vec4(a_Position +0.2, 1.0);
				  }
			)";
			std::string fragmentSrc = R"(
				  #version 330 core
					
				  layout(location = 0) out vec4 color;						

				  void main() 
				  {
						color = vec4(0.8, 0.2, 0.3, 1.0);
				  }
			)";
			//m_Shader = std::make_unique<Shader>(vertexSrc, fragmentSrc);
			m_Shader.reset(new Shader (vertexSrc, fragmentSrc));
	  }

	  Application::~Application()
	  {
	  }



	  void Application::Run()
	  {
			while (m_Running)
			{
				  glClearColor(0.2f, 0.2f, 0.2f, 1);
				  glClear(GL_COLOR_BUFFER_BIT);

				  m_Shader->Bind();
				  glBindVertexArray(m_VertexArray);
				  glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

				  for (Layer* layer : m_LayerStack)
				  {
						layer->OnUpdate();
				  }

				  m_ImGuiLayer->Begin();
				  for (Layer* layer : m_LayerStack)
						layer->OnImGuiRender();
				  m_ImGuiLayer->End();

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


