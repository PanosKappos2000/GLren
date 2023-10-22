#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(const glm::vec3& dir, const glm::vec3& amb,
	const glm::vec3& diff, const glm::vec3& spec)

	:direction(dir), ambient(amb), diffuse(diff), specular(spec)
{

}

DirectionalLight::~DirectionalLight()
{

}