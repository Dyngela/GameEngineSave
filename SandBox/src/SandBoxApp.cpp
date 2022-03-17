#include <GameEngine.h>

class ExempleLayer : public NE::Layer
{
public:
	  ExempleLayer()
			: Layer("Example")
	  {

	  }

	  void OnUpdate() override
	  {
			NE_INFO("ExempleLayer::update");
	  }

	  void OnEvent(NE::Event& event) override
	  {
			NE_TRACE("{0}", event);
	  }
};


class SandBox : public NE::Application
{
public:
	  SandBox()
	  {
			//PushLayer(new ExempleLayer());
			PushOverlay(new NE::ImGuiLayer());
	  }
	  ~SandBox()
	  {

	  }
};

NE::Application* NE::CreateApplication()
{
	  return new SandBox();
}
