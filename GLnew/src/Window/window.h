#pragma once

#include "Camera/camera.h"
#include "Entities/cube.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLFW_COLOR_RED		0.0f
#define GLFW_COLOR_BLUE		0.3f
#define GLFW_COLOR_GREEN	0.2f
#define GLFW_COLOR_ALPHA	1.0f

struct Stats
{
	int width;
	int height;
	const char* title;
	float deltatime;
	Camera* camera;

	Stats(int w = 1280, int h = 720, const char* t = "Graphics")
		:width(w), height(h), title(t), camera(nullptr), deltatime(0.0f)
	{

	}

	Stats(Stats& stats)
		:width(stats.width), height(stats.height), title(stats.title),
		camera(nullptr), deltatime(0.0f)
	{

	}
};

class Window
{
private:
	Stats m_stats;
	GLFWwindow* window;

	float m_prevFrame;

	static Window* s_instance;
public:
	Window(Stats& s = Stats());
	~Window();

	inline const void* GetWindowImplementation() const { return static_cast<void*>(window); }
	inline static const Window* GetWindowInstance() { return s_instance; }

	inline int GetWidth() const { return m_stats.width; }
	inline int GetHeight() const { return m_stats.height; }
	inline const char* GetTitle() const { return m_stats.title; }
	inline float GetDeltatime() const { return m_stats.deltatime; }
	inline const Camera* GetCamera() const { return m_stats.camera; }

	inline bool IsOpen() const { return !(glfwWindowShouldClose(window)); }

	void OnBufferUpdate();
	void OnUpdate();
};