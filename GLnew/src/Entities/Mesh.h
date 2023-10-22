#pragma once

#include "entity.h"
#include "Shader/Shader.h"

#include <vector>

class Mesh
{
private:
	std::vector<Vertex> m_vertices;
	std::vector<Tex> m_textures;
	std::vector<unsigned int> m_indices;

	unsigned int m_vertexBufferTag;
	unsigned int m_vertexArrayTag;
	unsigned int m_elementBufferTag;
public:
	Mesh(std::vector<Vertex>& vertices, std::vector<Tex>& textures, 
		std::vector<unsigned int>& indices);
	~Mesh();

	void OnUpdate();
	void Draw();
};