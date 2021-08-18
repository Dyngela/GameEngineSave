#pragma once

#include "GameEngine/Core.h"
#include "GameEngine/Events/Event.h"

namespace NE {

	  // Classe interface, on peut l'h�riter pour faire un layer, en r�digeant toute les m�thodes
	  class NE_API Layer
	  {
	  public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer();

			virtual void OnAttach() {}
			virtual void OnDetach() {}
			virtual void OnUpdate() {}
			virtual void OnEvent(Event& event) {}

			inline const std::string& GetName() const { return m_DebugName; }

	  protected:
			std::string m_DebugName;
	  };
}