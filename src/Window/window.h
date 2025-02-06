#pragma once

#include "Camera/camera.h"
#include "Entities/cube.h"

#define GLFW_COLOR_RED		0.0f
#define GLFW_COLOR_BLUE		0.3f
#define GLFW_COLOR_GREEN	0.2f
#define GLFW_COLOR_ALPHA	1.0f

uint8_t PlatformStartup(const char* appName, int32_t x, int32_t y, uint32_t width, uint32_t height);
void PlatformShutdown();

double PlatformGetAbsoluteTime();

void PlatformSleep(uint64_t ms);

uint8_t CreateOpenglDrawContext();

void OpenglSwapBuffers();

double GetDeltaTime();

void ClockSet();

void UpdateTime();