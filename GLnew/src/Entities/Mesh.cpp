#include "Mesh.h"
#include "Renderer/Renderer.h"
#include "Window/Window.h"

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<Tex>& textures,
	std::vector<unsigned int>& indices)

	:m_vertices(vertices), m_textures(textures), m_indices(indices),
	m_vertexBufferTag(0), m_vertexArrayTag(0), m_elementBufferTag(0)
{
	glGenVertexArrays(1, &m_vertexArrayTag);
	glGenBuffers(1, &m_vertexBufferTag);
	glGenBuffers(1, &m_elementBufferTag);

	glBindVertexArray(m_vertexArrayTag);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferTag);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferTag);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoordinates));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}

Mesh::~Mesh()
{

}

void Mesh::OnUpdate()
{
	Shader* shader = Shader::GetMeshShader();

	shader->Use();
	shader->SetUniformMatrix4D("View",
		Window::GetWindowInstance()->GetCamera()->GetLookAt());

	shader->SetUniformMatrix4D("Perspective", 
		Window::GetWindowInstance()->GetCamera()->GetPerspective());

	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, -5.0f, -3.0f));
	shader->SetUniformMatrix4D("Model", model);


	/*****************************************************************
	* Setting uniform variables for the Mesh's textures
	******************************************************************/
	unsigned int nrDiffuse = 0;
	unsigned int nrSpecular = 0;
	unsigned int nrNormal = 0;
	unsigned int nrHeight = 0;
	for (unsigned int i = 0; i < m_textures.size(); ++i)
	{
		switch (m_textures[i].type)
		{
			case TexType::TT_DiffuseMap:
			{
				shader->SetUniformInt(DiffuseTextureUniform(nrDiffuse), m_textures[i].tag);
				++nrDiffuse;
				break;
			}
			case TexType::TT_SpecularMap:
			{
				shader->SetUniformInt(SpecularTextureUniform(nrSpecular), m_textures[i].tag);
				++nrSpecular;
				break;
			}
			case TexType::TT_NormalMap:
			{
				shader->SetUniformInt(NormalTextureUniform(nrSpecular), m_textures[i].tag);
				++nrNormal;
				break;
			}
			case TexType::TT_HeightMap:
			{
				shader->SetUniformInt(HeightTextureUniform(nrSpecular), m_textures[i].tag);
				++nrHeight;
				break;
			}
		}
	}
	shader->SetUniformInt("Material.DiffuseTexNum", nrDiffuse);
	shader->SetUniformInt("Material.SpecularTexNum", nrSpecular);
	shader->SetUniformInt("Material.NormalTexNum", nrNormal);
	shader->SetUniformInt("Material.HeightTexNum", nrHeight);


	glBindVertexArray(m_vertexArrayTag);
	glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Mesh::Draw()
{

}