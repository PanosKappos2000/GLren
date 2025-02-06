#include "Renderer.h"
#include "Camera/camera.h"

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

	m_entities.resize(2);

	m_entities[0] = std::make_unique<SkyLight>();

	m_entities[1] = std::make_unique<Flashlight>(Camera::GetCamera()->GetPosition(), Camera::GetCamera()->GetDirection());
}

Renderer::~Renderer()
{
	
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

void Renderer::AddLightCube(const glm::vec3& position,
	const glm::vec3& ambient,
	const glm::vec3& diffuse,
	const glm::vec3& specular,
	float linear, float quadratic,
	float constant)
{
	if (m_lightCubeAmount == 0)
	{
		m_firstPointLightTag = m_entities.size();
	}

	m_entities.emplace_back(std::make_unique<LightCube>(position, ambient, diffuse, specular, linear, quadratic, constant));

	m_lightCubeAmount++;
}

void Renderer::AddRotatingCube(const char* innerTextureFilepath,
	const char* outerTextureFilepath,
	glm::vec3& pos,
	float rotationSpeed)
{
	m_entities.emplace_back(std::make_unique<RotatingCube>(innerTextureFilepath, outerTextureFilepath, pos, rotationSpeed));
}