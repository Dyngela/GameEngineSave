#include "nepch.h"
#include "WindowsInput.h"
#include "GameEngine/Application.h"

#include "GLFW/glfw3.h"

namespace NE {

	  Input* Input::s_Instance = new WindowsInput();

	  bool NE::WindowsInput::IsKeyPressedImpl(int keycode)
	  {
			auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
			auto state = glfwGetKey(window, keycode);
			return state == GLFW_PRESS || state == GLFW_REPEAT;
	  }

	  bool WindowsInput::IsMouseBoutonPressedImpl(int button)
	  {
			auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
			auto state = glfwGetKey(window, button);
			return state == GLFW_PRESS;


	  }

	  float WindowsInput::GetMouseXImpl()
	  {
			auto [x, y] = GetMousePosition();
			return x;
	  }

	  float WindowsInput::GetMouseYImpl()
	  {
			auto [x, y] = GetMousePosition();
			return y;
	  }

	  std::pair<float, float> WindowsInput::GetMousePositionImpl()
	  {
			auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
			double xpos, ypos;
			glfwGetCursorPos(window, &xpos, &ypos);
			return { (float)xpos , (float)ypos };
	  }

}


