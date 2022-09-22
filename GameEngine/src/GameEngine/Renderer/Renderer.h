#pragma once

namespace NE
{
	  enum class RendererAPI
	  {
			None = 0,
			OpenGL = 1
	  };

	  class Renderer
	  {
	  public:
			inline static RendererAPI GetAPI() { return s_RendererAPI; }
			inline static void SetAPI(RendererAPI name) { s_RendererAPI = name; };
	  private:
			static RendererAPI s_RendererAPI;
	  };
}