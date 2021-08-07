#include <GameEngine.h>

class SandBox : public NE::Application
{
public:
	  SandBox()
	  {

	  }
	  ~SandBox()
	  {

	  }
};

NE::Application* NE::CreateApplication()
{
	  return new SandBox();
}
