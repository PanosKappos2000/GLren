#pragma once

#include "Entities/cube.h"
#include "Entities/Model.h"
#include "Lighting/SkyLight.h"
#include "Lighting/Flashlight.h"

#include <iostream>
#include <vector>
#include <string>

class Renderer
{
private:
	std::vector<Entity*> m_entities;
	static Renderer* s_renderer;
	unsigned int m_skylightTag;
	unsigned int m_flashlightTag;
	unsigned int m_firstPointLightTag;

	unsigned int m_lightCubeAmount;
public:
	Renderer();
	~Renderer();

	inline void Append(Entity* entity) { m_entities.emplace_back(entity); }
	void AddLightCube(LightCube* cube);
	void AddRotatingCube(RotatingCube* cube);
	static const Renderer* GetRendererInstance() { return s_renderer; }
	inline SkyLight* GetSkylight() const 
	{ 
		return dynamic_cast<SkyLight*>(m_entities[m_skylightTag]); 
	}
	inline RotatingCube* GetRotatingCube(unsigned int tag)
	{
		return dynamic_cast<RotatingCube*>(m_entities[tag]);
	}
	inline LightCube* GetPointLight(unsigned int tag) const
	{
		return dynamic_cast<LightCube*>(m_entities[tag]);
	}
	inline Flashlight* GetFlashlight() const
	{
		return dynamic_cast<Flashlight*>(m_entities[m_flashlightTag]);
	}

	inline unsigned int GetFirstPointLightTag() const { return m_firstPointLightTag; }
	inline unsigned int GetLightCubeAmount() const { return m_lightCubeAmount; }

	inline unsigned int GetLightCubeCount() const { return m_lightCubeAmount; }

	void OnUpdate();
	void Draw();
};