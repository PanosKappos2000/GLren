#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


struct Spotlight
{
public:
	float constant;
	float linear;
	float quadratic;

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	
	glm::vec3 position;
	glm::vec3 direction;

	float outerCutoff;
	float innerCutoff;

	Spotlight(float iCut, float oCut, const glm::vec3& pos, 
		const glm::vec3& dir, const glm::vec3& amb, const glm::vec3& diff, 
		const glm::vec3& spec, float lin, float quad, float cnst)

		:direction(dir), constant(cnst), linear(lin), quadratic(quad),
		ambient(amb), diffuse(diff), specular(spec),
		position(pos), outerCutoff(oCut), innerCutoff(iCut)
	{

	}
};