#include <GameEngine.h>
#include "glm/glm.hpp"
#include "imgui/imgui.h"

class ExempleLayer : public NE::Layer
{
public:
	  ExempleLayer()
			: Layer("Example")
	  { 

	  }

	  void OnUpdate() override
	  {
			if (NE::Input::IsKeyPressed(NE_KEY_TAB))
			{
				  NE_INFO("tab is pressed");
			}
	  }

	  void OnEvent(NE::Event& event) override
	  {
			//NE_TRACE("{0}", event);
	  }

	  virtual void OnImGuiRender() override
	  {
			ImGui::Begin("Test");
			ImGui::Text("Hello World");
			ImGui::End();
	  }
};




class SandBox : public NE::Application
{
public:
	  SandBox()
	  {
			PushLayer(new ExempleLayer());
	  }
	  ~SandBox()
	  {

	  }
};

NE::Application* NE::CreateApplication()
{
	  return new SandBox();
}
