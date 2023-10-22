#include "Renderer.h"
#include "Window/window.h"

Renderer* Renderer::s_renderer;

Renderer::Renderer()
	:m_skylightTag(0), m_flashlightTag(1), m_lightCubeAmount(0),
	m_firstPointLightTag(0)
{
	if (!s_renderer)
	{
		s_renderer = this;
	}
	else
	{
		std::cout << "The renderer is a singleton,";
		std::cout << "It can only be initialized once\n";
		__debugbreak();
	}
	m_entities.emplace_back(new SkyLight());
	m_entities.emplace_back(new Flashlight
	(Window::GetWindowInstance()->GetCamera()->GetPosition(),
	Window::GetWindowInstance()->GetCamera()->GetDirection()));
}

Renderer::~Renderer()
{
	for (unsigned int i = 0; i < m_entities.size(); ++i)
	{
		delete m_entities[i];
	}
}

void Renderer::OnUpdate()
{
	for (unsigned int i = 0; i < m_entities.size(); ++i)
	{
		m_entities[i]->OnUpdate();
	}
}

void Renderer::Draw()
{
	for (unsigned int i = 0; i < m_entities.size(); ++i)
	{
		m_entities[i]->Draw();
	}
}

void Renderer::AddLightCube(LightCube* cube)
{
	if (m_lightCubeAmount == 0)
	{
		m_firstPointLightTag = m_entities.size();
	}
	m_entities.emplace_back(cube);
	m_lightCubeAmount++;
}

void Renderer::AddRotatingCube(RotatingCube* cube)
{
	m_entities.emplace_back(cube);
}