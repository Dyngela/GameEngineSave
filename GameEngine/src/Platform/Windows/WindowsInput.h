#pragma once

#include "GameEngine/Input.h"

namespace NE {

	  class WindowsInput : public Input
	  {
			protected:
				  virtual bool IsKeyPressedImpl(int keycode) override;
				  virtual bool IsMouseBoutonPressedImpl(int button) override;
				  virtual float GetMouseXImpl() override;
				  virtual float GetMouseYImpl() override;
				  virtual std::pair<float, float> GetMousePositionImpl() override;

	  };

}
