#include "glfwCallbacks.h"
#include "Renderer/Renderer.h"

void GlfwWindowSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void GlfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Stats* stats = static_cast<Stats*>(glfwGetWindowUserPointer(window));
	switch (action)
	{
		case GLFW_PRESS:
		case GLFW_REPEAT:
		{
			switch (key)
			{
				case GLFW_KEY_ESCAPE:
				{
					glfwSetWindowShouldClose(window, true);
					break;
				}
				case GLFW_KEY_W:
				{
					stats->camera->MoveForward(stats->deltatime);
					break;
				}
				case GLFW_KEY_S:
				{
					stats->camera->MoveBackward(stats->deltatime);
					break;
				}
				case GLFW_KEY_D:
				{
					stats->camera->MoveRight(stats->deltatime);
					break;
				}
				case GLFW_KEY_A:
				{
					stats->camera->MoveLeft(stats->deltatime);
					break;
				}
				default:
				{
					break;
				}
			}
			break;
		}
		default:
		{
			break;
		}
	}
}

void GlfwCursorPosCallback(GLFWwindow* window, double xPos, double yPos)
{
	Stats* stats = static_cast<Stats*>(glfwGetWindowUserPointer(window));
	stats->camera->Rotate((float)xPos, (float)yPos);
}