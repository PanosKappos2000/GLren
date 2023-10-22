#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct DirectionalLight
{
public:
	glm::vec3 direction;

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
public:
	DirectionalLight(const glm::vec3& dir, const glm::vec3& amb, 
		const glm::vec3& diff, const glm::vec3& spec);

	~DirectionalLight();
};