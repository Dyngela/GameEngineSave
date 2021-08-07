#pragma once

#ifdef NE_PLATFORM_WINDOWS

extern NE::Application* NE::CreateApplication();

int main(int argc, char** argv)
{
	  NE::Log::Init();
	  NE_CORE_WARN("Log initialise");
	  int a = 4;
	  NE_INFO("Hello my friend! var={0}", a);

	  //printf("My game engine works for now on!");
	  auto app = NE::CreateApplication();
	  app->Run();
	  delete app;
}

#endif