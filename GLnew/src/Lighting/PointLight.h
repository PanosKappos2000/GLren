#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct PointLight
{
public:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

	float constant;
	float linear;
	float quadratic;

	glm::vec3 position;
public:
	PointLight(const glm::vec3& pos, const glm::vec3& amb, const glm::vec3& diff,
		const glm::vec3& spec, float lin, float quad, float cnst);
	~PointLight();
};