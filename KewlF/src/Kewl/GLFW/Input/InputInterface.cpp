#include "InputInterface.hpp"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Kewl {

	bool InputInterface::IsKeyDown(KeyCode keycode)
	{
		GLFWwindow* glfwWindow = GetGlfwWindow();
		int state = glfwGetKey(glfwWindow, (int)keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool InputInterface::IsMouseButtonDown(MouseButton button)
	{
		GLFWwindow* glfwWindow = GetGlfwWindow();
		int state = glfwGetMouseButton(glfwWindow, (int)button);
		return state == GLFW_PRESS;
	}

	glm::vec2 InputInterface::GetMousePosition()
	{
		GLFWwindow* glfwWindow = GetGlfwWindow();

		double x, y;
		glfwGetCursorPos(glfwWindow, &x, &y);
		return { (float)x, (float)y };
	}

	void InputInterface::SetCursorMode(CursorMode mode)
	{
		GLFWwindow* glfwWindow = GetGlfwWindow();
		glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL + (int)mode);
	}

}// namespace Kewl