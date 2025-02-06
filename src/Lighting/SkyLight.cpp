#include "SkyLight.h"

SkyLight::SkyLight(const glm::vec3& dir, const glm::vec3& amb,
	const glm::vec3& diff, const glm::vec3& spec)
	:m_light(dir, amb, diff, spec)
{

}

SkyLight::~SkyLight()
{

}

void SkyLight::OnUpdate()
{

}

void SkyLight::Draw()
{

}