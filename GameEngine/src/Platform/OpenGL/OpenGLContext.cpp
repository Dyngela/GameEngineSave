#include "nepch.h"
#include "OpenGLContext.h"
#include "GLFW/glfw3.h"
#include <glad/glad.h>

namespace NE
{
	  OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
			: m_WindowHandle(windowHandle)
	  {
	  }

	  void OpenGLContext::Init()
	  {
			glfwMakeContextCurrent(m_WindowHandle);
			int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
			NE_CORE_ASSERT(status, "Failed to initialize Glad");

			NE_CORE_INFO(glGetString(GL_RENDERER));
	  }

	  void OpenGLContext::SwapBuffers()
	  {
			glfwSwapBuffers(m_WindowHandle);
	  }

}