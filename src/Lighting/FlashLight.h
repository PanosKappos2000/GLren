#pragma once

#include "SpotLight.h"
#include "Entities/entity.h"
#include "Window/window.h"

#define SPOTLIGHT_DEFAULT_INNER_CUTOFF		12.5f
#define SPOTLIGHT_DEFAULT_OUTER_CUTOFF		17.0f
#define SPOTLIGHT_DEFAULT_AMBIENT			glm::vec3(0.2f, 0.2f, 0.2f)
#define SPOTLIGHT_DEFAULT_DIFFUSE			glm::vec3(1.0f, 1.0f, 1.0f)
#define SPOTLIGHT_DEFAULT_SPECULAR			glm::vec3(1.0f, 1.0f, 1.0f)
#define SPOTLIGHT_DEFAULT_LINEAR			0.14
#define SPOTLIGHT_DEFAULT_QUADRATIC			0.07	
#define SPOTLIGHT_DEFAULT_CONSTANT			1.0f

class Flashlight : public Entity
{
private:
	Spotlight m_light;
public:
	Flashlight(const glm::vec3& position, const glm::vec3& direction, 
		float innerCutoff = SPOTLIGHT_DEFAULT_INNER_CUTOFF, 
		float outerCutoff = SPOTLIGHT_DEFAULT_OUTER_CUTOFF,
		const glm::vec3& amb = SPOTLIGHT_DEFAULT_AMBIENT,
		const glm::vec3& diff = SPOTLIGHT_DEFAULT_DIFFUSE,
		const glm::vec3& spec = SPOTLIGHT_DEFAULT_SPECULAR,
		float lin = SPOTLIGHT_DEFAULT_LINEAR, float quad = SPOTLIGHT_DEFAULT_QUADRATIC, 
		float cnst = SPOTLIGHT_DEFAULT_CONSTANT);

	~Flashlight();

	inline const glm::vec3& GetPosition() const
	{
		return m_light.position;
	}

	inline const glm::vec3& GetDirection() const
	{
		return m_light.direction;
	}

	inline const glm::vec3& GetDiffuseLighting() const { return m_light.diffuse; }
	inline const glm::vec3& GetSpecularLighting() const { return m_light.specular; }
	inline const glm::vec3& GetAmbientLighting() const { return m_light.ambient; }

	inline float GetInnerCutoff() const { return cos(glm::radians(m_light.innerCutoff)); }
	inline float GetOuterCutoff() const { return cos(glm::radians(m_light.outerCutoff)); }

	inline float GetConstantAttenuationTerm() const { return m_light.constant; }
	inline float GetLinearAttenuationTerm() const { return m_light.linear; }
	inline float GetQuadraticAttenuationTerm() const { return m_light.quadratic; }

	void OnUpdate() override;
	void Draw() override;
};