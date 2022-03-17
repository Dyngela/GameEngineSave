#pragma once

#include "GameEngine/Layer.h"

#include "GameEngine/Events/Event.h"
#include "GameEngine/Events/KeyEvent.h"
#include "GameEngine/Events/MouseEvent.h"
#include "GameEngine/Events/ApplicationEvent.h"

namespace NE {

	  class NE_API ImGuiLayer : public Layer
	  {
	  public:
			ImGuiLayer();
			~ImGuiLayer();

			void OnAttach();
			void OnDetach();
			void OnUpdate();
			void OnEvent(Event& event);

	  private:
			bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
			bool OnMouseButtonReleaseEvent(MouseButtonReleasedEvent& e);
			bool OnMouseMovedEvent(MouseMovedEvent& e);
			bool OnMouseScrollEvent(MouseScrolledEvent& e);
			bool OnKeyPressedEvent(KeyPressedEvent& e);
			bool OnKeyReleasedEvent(KeyReleasedEvent& e);
			bool OnKeyTypedEvent(KeyTypedEvent& e);
			bool OnWindowResizedEvent(WindowResizeEvent& e);


	  private:
			float m_Time = 0.0f;
	  };
}
