#pragma once

#ifdef NE_PLATFORM_WINDOWS

extern NE::Application* NE::CreateApplication();

int main(int argc, char** argv)
{
	  NE::Log::Init();
	  NE_CORE_WARN("Log initialise");

	  auto app = NE::CreateApplication();
	  app->Run();
	  delete app;
}

#endif