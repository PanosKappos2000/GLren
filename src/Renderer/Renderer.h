#pragma once

#include "Entities/cube.h"
#include "Lighting/SkyLight.h"
#include "Lighting/Flashlight.h"

#include <iostream>
#include <vector>
#include <string>

class Renderer
{
private:
	std::vector<std::unique_ptr<Entity>> m_entities;
	static Renderer* s_renderer;
	unsigned int m_skylightTag;
	unsigned int m_flashlightTag;
	unsigned int m_firstPointLightTag;

	unsigned int m_lightCubeAmount;
public:
	Renderer();
	~Renderer();

	static Renderer* GetRendererInstance() { return s_renderer; }

	inline void ReserveEntities(size_t size){
		m_entities.reserve(size);
	}

	void AddLightCube(const glm::vec3& position = LIGHT_CUBE_DEFAULT_POSITION,
		const glm::vec3& ambient = LIGHT_CUBE_DEFAULT_AMBIENT,
		const glm::vec3& diffuse = LIGHT_CUBE_DEFAULT_DIFFUSE,
		const glm::vec3& specular = LIGHT_CUBE_DEFAULT_SPECULAR,
		float linear = LIGHT_CUBE_DEFAULT_LINEAR, float quadratic = LIGHT_CUBE_DEFAULT_QUADRATIC,
		float constant = LIGHT_CUBE_DEFAULT_CONSTANT);

	void AddRotatingCube(const char* innerTextureFilepath,
		const char* outerTextureFilepath,
		glm::vec3& pos = CUBE_DEFAULT_POSITION,
		float rotationSpeed = ROTATING_CUBE_DEFAULT_ROTATION_SPEED);

	inline SkyLight* GetSkylight() 
	{ 
		return dynamic_cast<SkyLight*>(m_entities[m_skylightTag].get()); 
	}

	inline RotatingCube* GetRotatingCube(unsigned int tag)
	{
		return dynamic_cast<RotatingCube*>(m_entities[tag].get());
	}

	inline LightCube* GetPointLight(unsigned int tag)
	{
		return dynamic_cast<LightCube*>(m_entities[tag].get());
	}

	inline Flashlight* GetFlashlight()
	{
		return dynamic_cast<Flashlight*>(m_entities[m_flashlightTag].get());
	}

	inline unsigned int GetFirstPointLightTag() const { return m_firstPointLightTag; }
	inline unsigned int GetLightCubeAmount() const { return m_lightCubeAmount; }

	inline unsigned int GetLightCubeCount() const { return m_lightCubeAmount; }

	void OnUpdate();
	void Draw();
};