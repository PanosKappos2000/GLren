#pragma once

#include "window.h"

void GlfwWindowSizeCallback(GLFWwindow* window, int width, int height);

void GlfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

void GlfwCursorPosCallback(GLFWwindow* window, double xPos, double yPos);