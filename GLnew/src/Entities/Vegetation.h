#pragma once

#include "entity.h"
#include "Texture/texture.h"
#include "Shader/Shader.h"

class Vegetation : public Entity
{
private:
	glm::vec3 m_position;

	float m_vertices[8 * 6];

	unsigned int m_vertexArrayTag;
	Tex m_tex;
public:
	Vegetation(const glm::vec3& pos, const std::string& texFile);
	~Vegetation();

	void OnUpdate() override;
	void Draw() override;
};