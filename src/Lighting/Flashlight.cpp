#include "FlashLight.h"
#include "Camera/camera.h"

Flashlight::Flashlight(const glm::vec3& position, const glm::vec3& direction,
	float innerCutoff, float outerCutoff, const glm::vec3& amb, 
	const glm::vec3& diff, const glm::vec3& spec, float lin, float quad, float cnst)

	:m_light(innerCutoff, outerCutoff, position, direction, amb, diff, spec, lin, quad, cnst)
{

}

Flashlight::~Flashlight()
{

}

void Flashlight::OnUpdate()
{
	m_light.position = Camera::GetCamera()->GetPosition();
	m_light.direction = Camera::GetCamera()->GetDirection();
}

void Flashlight::Draw()
{

}