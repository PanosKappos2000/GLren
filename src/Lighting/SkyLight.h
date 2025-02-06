#pragma once

#include "Lighting/DirectionalLight.h"
#include "Entities/entity.h"

#define SKYLIGHT_DEFAULT_DIRECTION		glm::vec3(-0.2f, -1.0f, -0.3f)
#define SKYLIGHT_DEFAULT_AMBIENT		glm::vec3(0.2f, 0.2f, 0.2f)
#define SKYLIGHT_DEFAULT_DIFFUSE		glm::vec3(0.6f, 0.6f, 0.6f)
#define SKYLIGHT_DEFAULT_SPECULAR		glm::vec3(0.85f, 0.85f, 0.85f)

class SkyLight : public Entity
{
private:
	DirectionalLight m_light;
public:
	SkyLight(const glm::vec3& dir = SKYLIGHT_DEFAULT_DIRECTION, 
		const glm::vec3& amb = SKYLIGHT_DEFAULT_AMBIENT,
		const glm::vec3& diff = SKYLIGHT_DEFAULT_DIFFUSE,
		const glm::vec3& spec = SKYLIGHT_DEFAULT_SPECULAR);
	~SkyLight();

	inline const glm::vec3& GetAmbientLighting() const { return m_light.ambient; }
	inline const glm::vec3& GetDiffuseLighting() const { return m_light.diffuse; }
	inline const glm::vec3& GetSpecularLighting() const { return m_light.specular; }
	inline const glm::vec3& GetDirection() const { return m_light.direction; }

	inline void SetAmbientLighting(const glm::vec3& amb)
	{
		m_light.ambient = amb;
	}

	inline void SetDiffuseLighting(const glm::vec3& diff)
	{
		m_light.diffuse = diff;
	}

	inline void SetSpecularLighting(const glm::vec3& spec)
	{
		m_light.specular = spec;
	}

	void OnUpdate() override;
	void Draw() override;
};