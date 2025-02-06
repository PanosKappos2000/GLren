#pragma once

#include "entity.h"
#include "Shader/Shader.h"
#include "Texture/texture.h"
#include "Lighting/PointLight.h"
#include "Materials/Material.h"

#define ROTATING_CUBE_DEFAULT_ROTATION_SPEED		10.0f
#define CUBE_DEFAULT_POSITION						glm::vec3(0.0f, 0.0f, 0.0f)

class RotatingCube : public Entity
{
private:
	Texture m_innerTexture;
	Texture m_outerTexture;
	Material m_material;

	float m_vertices[8 * 36];
	unsigned int m_vertexBufferTag;
	unsigned int m_vertexArrayTag;

	glm::vec3 m_position;

	float m_rotationSpeed;
public:
	RotatingCube(const char* innerTextureFilepath,
		const char* outerTextureFilepath,
		glm::vec3& pos = CUBE_DEFAULT_POSITION,
		float rotationSpeed = ROTATING_CUBE_DEFAULT_ROTATION_SPEED);

	~RotatingCube();

	void SetMaterial(Material& material);

	void OnUpdate() override;
	void Draw() override;
};





#define LIGHT_CUBE_DEFAULT_AMBIENT			glm::vec3(0.3f, 0.3f, 0.3f)
#define LIGHT_CUBE_DEFAULT_DIFFUSE			glm::vec3(0.8f, 0.8f, 0.8f)
#define LIGHT_CUBE_DEFAULT_SPECULAR			glm::vec3(1.0f, 1.0f, 1.0f)

#define LIGHT_CUBE_DEFAULT_LINEAR			0.045f
#define LIGHT_CUBE_DEFAULT_QUADRATIC		0.0075f
#define LIGHT_CUBE_DEFAULT_CONSTANT			1.0f

#define LIGHT_CUBE_DEFAULT_POSITION			glm::vec3(0.0f, 10.0f, -17.0f)

#define LIGHT_CUBE_ON_COLOR					glm::vec3(1.0f, 1.0f, 1.0f)
#define LIGHT_CUBE_OFF_COLOR				glm::vec3(0.0f, 0.0f, 0.0f)

class LightCube : public Entity
{
private:
	float m_vertices[3 * 36];
	unsigned int m_vertexBufferTag;
	unsigned int m_vertexArrayTag;
	
	glm::vec3 m_position;

	glm::vec3 m_color;

	PointLight m_light;
public:
	LightCube(const glm::vec3& position = LIGHT_CUBE_DEFAULT_POSITION,
		const glm::vec3& ambient = LIGHT_CUBE_DEFAULT_AMBIENT,
		const glm::vec3& diffuse = LIGHT_CUBE_DEFAULT_DIFFUSE,
		const glm::vec3& specular = LIGHT_CUBE_DEFAULT_SPECULAR,
		float linear = LIGHT_CUBE_DEFAULT_LINEAR, float quadratic = LIGHT_CUBE_DEFAULT_QUADRATIC,
		float constant = LIGHT_CUBE_DEFAULT_CONSTANT);

	~LightCube();

	inline const glm::vec3& GetPosition() const { return m_position; }
	inline const glm::vec3& GetAmbientLighting() const { return m_light.ambient; }
	inline const glm::vec3& GetDiffuseLighting() const { return m_light.diffuse; }
	inline const glm::vec3& GetSpecularLighting() const { return m_light.specular; }
	inline float GetConstantAttenuationTerm() const { return m_light.constant; }
	inline float GetLinearAttenuationTerm() const { return m_light.linear; }
	inline float GetQuadraticAttenuationTerm() const { return m_light.quadratic; }

	inline void SetAmbientLighting(glm::vec3& amb)
	{
		m_light.ambient = amb;
	}
	
	inline void SetDiffuseLighting(glm::vec3& diff)
	{
		m_light.diffuse = diff;
	}

	inline void SetSpecularLighting(glm::vec3& spec)
	{
		m_light.specular = spec;
	}

	inline void SetLightColor(const glm::vec3& color)
	{
		m_color = color;
	}

	void OnUpdate() override;
	void Draw() override;
};