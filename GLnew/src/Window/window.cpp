#include "window.h"
#include "glfwCallbacks.h"

Window* Window::s_instance;

Window::Window(Stats& s)
	:m_stats(s), m_prevFrame(0.0f)
{
	//The constructor creates a static Window pointer,
	//and checks if only one window is created
	if (!s_instance)
		s_instance = this;
	else
	{
		std::cout << "Window is a singleton, thus only one instance is allowed\n";
		__debugbreak();
	}

	//GLFW is setup
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//The window is created and its data is saved to the user pointer
	window = glfwCreateWindow(m_stats.width, m_stats.height, m_stats.title, nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSetWindowUserPointer(window, static_cast<void*>(&m_stats));

	//GLAD is setup
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, m_stats.width, m_stats.height);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_STENCIL_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_CULL_FACE);

	//glfw callbacks are setup
	glfwSetWindowSizeCallback(window, GlfwWindowSizeCallback);
	glfwSetKeyCallback(window, GlfwKeyCallback);
	glfwSetCursorPosCallback(window, GlfwCursorPosCallback);

	//The main camera is created
	m_stats.camera = new Camera();
}

Window::~Window()
{
	//The destructor deletes all manually allocated pointers before closing the window
	delete m_stats.camera;
	glfwTerminate();
}

void Window::OnBufferUpdate()
{
	//Deltatime is calculated first on each frame
	float newFrame = static_cast<float>(glfwGetTime());
	m_stats.deltatime = newFrame - m_prevFrame;
	m_prevFrame = newFrame;

	//The color buffer and used bits are updated
	glClearColor(GLFW_COLOR_RED, GLFW_COLOR_GREEN, GLFW_COLOR_BLUE, GLFW_COLOR_ALPHA);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Window::OnUpdate()
{
	//After the rendering is finished, it checks for events and swaps buffers
	glfwPollEvents();
	glfwSwapBuffers(window);
}