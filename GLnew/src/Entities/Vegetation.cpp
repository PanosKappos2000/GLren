#include "Vegetation.h"
#include "Window/window.h"
#include "Renderer/Renderer.h"

Vegetation::Vegetation(const glm::vec3& pos, const std::string& texFile)
	:m_position(pos), 
	m_vertices
	{
		-0.5f, -0.5f, -0.5f,		0.0f, 0.0f, -1.0f,			0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f,			0.0f, 0.0f, -1.0f,			0.0f, 1.0f,
		0.5f, 0.5f, -0.5f,			0.0f, 0.0f, -1.0f,			1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,			0.0f, 0.0f, -1.0f,			1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,		0.0f, 0.0f, -1.0f,			0.0f, 0.0f,
		0.5f, 0.5f, -0.5f,			0.0f, 0.0f, -1.0f,			1.0f, 1.0f
	}
{
	m_tex.tag = TextureFromFile(texFile);
	m_tex.type = TexType::TT_DiffuseMap;

	glGenVertexArrays(1, &m_vertexArrayTag);
	glBindVertexArray(m_vertexArrayTag);
	unsigned int vertexBufferTag;
	glGenBuffers(1, &vertexBufferTag);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferTag);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}

Vegetation::~Vegetation()
{

}

void Vegetation::OnUpdate()
{
	Shader* shader = Shader::GetVegetationShader();

	shader->Use();

	glDisable(GL_CULL_FACE);

	shader->SetUniformMatrix4D("View",
		Window::GetWindowInstance()->GetCamera()->GetLookAt());
	shader->SetUniformMatrix4D("Perspective",
		Window::GetWindowInstance()->GetCamera()->GetPerspective());
	glm::mat4 model(1.0f);
	model = glm::translate(model, m_position);
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	shader->SetUniformMatrix4D("Model", model);

	shader->SetUniformInt("Material.DiffuseTex", m_tex.tag);
	shader->SetUniformInt("Material.SpecularTex", m_tex.tag);

	shader->SetUniformMatrix3D("NormalMatrix", glm::mat3(glm::transpose(glm::inverse(model))));
	shader->SetUniformVector3D("CamPos",
		Window::GetWindowInstance()->GetCamera()->GetPosition());


	/*********************************************************************
	*Setting uniform variables for the directional light calculations
	**********************************************************************/

	shader->SetUniformVector3D("DirectionalLight.Ambient",
		Renderer::GetRendererInstance()->GetSkylight()->GetAmbientLighting());
	
	shader->SetUniformVector3D("DirectionalLight.Diffuse",
		Renderer::GetRendererInstance()->GetSkylight()->GetDiffuseLighting());

	shader->SetUniformVector3D("DirectionalLight.Specular",
		Renderer::GetRendererInstance()->GetSkylight()->GetSpecularLighting());

	shader->SetUniformVector3D("DirectionalLight.Direction",
		Renderer::GetRendererInstance()->GetSkylight()->GetDirection());

	glBindVertexArray(m_vertexArrayTag);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

	glEnable(GL_CULL_FACE);
}

void Vegetation::Draw()
{

}