#pragma once

#include <glfw/glfw3.h>
#include <glm/glm.hpp>

#include "Kewl/Util/KeyCodes.hpp"

namespace Kewl {

	class InputInterface
	{
	protected:
		//GLFWwindow* glfwWindow;
		virtual GLFWwindow* GetGlfwWindow() = 0;
	public:
		bool IsKeyDown(KeyCode keycode);
		bool IsMouseButtonDown(MouseButton button);
		glm::vec2 GetMousePosition();
		void SetCursorMode(CursorMode mode);
	};

} // namespace Kewl
