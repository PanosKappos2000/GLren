#include "PointLight.h"

PointLight::PointLight(const glm::vec3& pos, const glm::vec3& amb,
	const glm::vec3& diff, const glm::vec3& spec, float lin, float quad, float cnst)

	:position(pos), ambient(amb), diffuse(diff), specular(spec), linear(lin), 
	quadratic(quad), constant(cnst)
{

}

PointLight::~PointLight()
{

}