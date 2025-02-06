#include "cube.h"
#include "Window/window.h"
#include "Renderer/Renderer.h"

RotatingCube::RotatingCube(const char* innerTextureFilepath,
	const char* outerTextureFilepath, glm::vec3& pos, float rotationSpeed)
	:m_innerTexture(innerTextureFilepath),m_vertexArrayTag(0), m_vertexBufferTag(0),
	m_outerTexture(outerTextureFilepath), m_rotationSpeed(rotationSpeed),
	m_position(pos),
	m_vertices
	{
		-0.5f, 0.5f, -0.5f,			0.0f, 0.0f, -1.0f,		0.0f, 1.0f,
		0.5f, 0.5f, -0.5f,			0.0f, 0.0f, -1.0f,		1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,		0.0f, 0.0f, -1.0f,		0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,			0.0f, 0.0f, -1.0f,		1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,		0.0f, 0.0f, -1.0f,		0.0f, 0.0f,
		0.5f, 0.5f, -0.5f,			0.0f, 0.0f, -1.0f,		1.0f, 1.0f,

		0.5f, 0.5f, 0.5f,			0.0f, 0.0f, 1.0f,		0.0f, 1.0f,
		-0.5f, 0.5f, 0.5f,			0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
		0.5f, -0.5f, 0.5f,			0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,			0.0f, 0.0f, 1.0f,		1.0f, 0.0f,
		0.5f, -0.5f, 0.5f,			0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f,			0.0f, 0.0f, 1.0f,		1.0f, 1.0f,

		-0.5f, 0.5f, 0.5f,			-1.0f, 0.0f, 0.0f,		0.0f, 1.0f,
		-0.5f, 0.5f, -0.5f,			-1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
		-0.5f, -0.5f, 0.5f,			-1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,		-1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,			-1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f,			-1.0f, 0.0f, 0.0f,		1.0f, 1.0f,

		0.5f, 0.5f, -0.5f,			1.0f, 0.0f, 0.0f,		0.0f, 1.0f,
		0.5f, 0.5f, 0.5f,			1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,			1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		0.5f, -0.5f, 0.5f,			1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
		0.5f, -0.5f, -0.5f,			1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		0.5f, 0.5f, 0.5f,			1.0f, 0.0f, 0.0f,		1.0f, 1.0f,

		-0.5f, 0.5f, 0.5f,			0.0f, 1.0f, 0.0f,		0.0f, 1.0f,
		0.5f, 0.5f, 0.5f,			0.0f, 1.0f, 0.0f,		1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f,			0.0f, 1.0f, 0.0f,		0.0f, 0.0f,
		0.5f, 0.5f, -0.5f,			0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f,			0.0f, 1.0f, 0.0f,		0.0f, 0.0f,
		0.5f, 0.5f, 0.5f,			0.0f, 1.0f, 0.0f,		1.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,		0.0f, -1.0f, 0.0f,		0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,			0.0f, -1.0f, 0.0f,		1.0f, 1.0f,
		-0.5f, -0.5f, 0.5f,			0.0f, -1.0f, 0.0f,		0.0f, 0.0f,
		0.5f, -0.5f, 0.5f,			0.0f, -1.0f, 0.0f,		1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,			0.0f, -1.0f, 0.0f,		0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,			0.0f, -1.0f, 0.0f,		1.0f, 1.0f
	}
{
	glGenVertexArrays(1, &m_vertexArrayTag);
	glBindVertexArray(m_vertexArrayTag);
	glGenBuffers(1, &m_vertexBufferTag);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferTag);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	Shader::GetRotatingCubeShader()->Use();

	glm::mat4 perspective = Camera::GetCamera()->GetPerspective();
	Shader::GetRotatingCubeShader()->SetUniformMatrix4D("Perspective", perspective);
}

RotatingCube::~RotatingCube()
{

}

void RotatingCube::SetMaterial(Material& mat)
{
	m_material.ambient = mat.ambient;
	m_material.diffuse = mat.diffuse;
	m_material.specular = mat.specular;
	m_material.shininess = mat.shininess;

	Shader::GetRotatingCubeShader()->Use();
	Shader::GetRotatingCubeShader()->SetUniformVector3D("material.ambient", m_material.ambient);
	Shader::GetRotatingCubeShader()->SetUniformVector3D("material.diffuse", m_material.diffuse);
	Shader::GetRotatingCubeShader()->SetUniformVector3D("material.specular", m_material.specular);
	Shader::GetRotatingCubeShader()->SetUniformFloat("material.shininess", m_material.shininess * 128);
}

void RotatingCube::OnUpdate()
{
	Shader::GetRotatingCubeShader()->Use();

	glm::mat4 view(1.0f);
	view = Camera::GetCamera()->GetLookAt();
	glm::mat4 model(1.0f);
	model = glm::translate(model, m_position);
	/*glm::vec3 dir = glm::normalize(glm::vec3(0.0f, 1.0f, 0.0f));
	glm::vec3 move = 0.01f * dir;
	m_position += move;*/
	model = glm::rotate(model,
		glm::radians(m_rotationSpeed * float(GetDeltaTime())), glm::vec3(1.0f, 1.0f, 1.0f));

	//Shader::GetRotatingCubeShader()->SetUniformMatrix3D("Scale", glm::mat4(2.0f));

	/*************************************************************************************************
	* Setting up universal uniform variables, that apply for positions and all types of light sources
	**************************************************************************************************/
	Shader::GetRotatingCubeShader()->SetUniformMatrix4D("Model", model);
	Shader::GetRotatingCubeShader()->SetUniformMatrix4D("View", view);
	Shader::GetRotatingCubeShader()->SetUniformMatrix3D(
		"NormalMatrix", glm::transpose(glm::inverse(glm::mat3(model))));

	Shader::GetRotatingCubeShader()->SetUniformVector3D("ViewPosition",
		Camera::GetCamera()->GetPosition());

	Shader::GetRotatingCubeShader()->SetUniformFloat("Material.Shininess", m_material.shininess * 128);
	Shader::GetRotatingCubeShader()->SetUniformFloat("Material.Ambient", 0.2f);
	Shader::GetRotatingCubeShader()->SetUniformInt("Material.Diffuse", m_innerTexture.GetTag());
	Shader::GetRotatingCubeShader()->SetUniformInt("Material.Specular", m_outerTexture.GetTag());


	/**************************************************************************************************
	* Setting up uniform variables, that apply only for the directional skylight calculations
	***************************************************************************************************/
	Shader::GetRotatingCubeShader()->SetUniformVector3D("DirectionalLight.Direction",
		Renderer::GetRendererInstance()->GetSkylight()->GetDirection());

	Shader::GetRotatingCubeShader()->SetUniformVector3D("DirectionalLight.Ambient",
		Renderer::GetRendererInstance()->GetSkylight()->GetAmbientLighting());

	Shader::GetRotatingCubeShader()->SetUniformVector3D("DirectionalLight.Diffuse",
		Renderer::GetRendererInstance()->GetSkylight()->GetDiffuseLighting());

	Shader::GetRotatingCubeShader()->SetUniformVector3D("DirectionalLight.Specular",
		Renderer::GetRendererInstance()->GetSkylight()->GetSpecularLighting());


	/******************************************************************************************************
	* Setting up uniform variables, that apply for the calculations used for the point lights in the scene
	********************************************************************************************************/
	unsigned int currentPointLight = Renderer::GetRendererInstance()->GetFirstPointLightTag();
	Shader::GetRotatingCubeShader()->SetUniformInt("PointLightNum", 
		Renderer::GetRendererInstance()->GetLightCubeAmount());

	for (unsigned int i = 0; i < 5; ++i)
	{
		Shader::GetRotatingCubeShader()->SetUniformVector3D(PointLightPositionUniform(i),
			Renderer::GetRendererInstance()->GetPointLight(currentPointLight)->GetPosition());

		Shader::GetRotatingCubeShader()->SetUniformVector3D(PointLightAmbientUniform(i),
			Renderer::GetRendererInstance()->GetPointLight(currentPointLight)->GetAmbientLighting());

		Shader::GetRotatingCubeShader()->SetUniformVector3D(PointLightDiffuseUniform(i),
			Renderer::GetRendererInstance()->GetPointLight(currentPointLight)->GetDiffuseLighting());
		
		Shader::GetRotatingCubeShader()->SetUniformVector3D(PointLightSpecularUniform(i),
			Renderer::GetRendererInstance()->GetPointLight(currentPointLight)->GetSpecularLighting());

		Shader::GetRotatingCubeShader()->SetUniformFloat(PointLightConstantUniform(i),
			Renderer::GetRendererInstance()->GetPointLight(currentPointLight)->GetConstantAttenuationTerm());

		Shader::GetRotatingCubeShader()->SetUniformFloat(PointLightLinearUniform(i),
			Renderer::GetRendererInstance()->GetPointLight(currentPointLight)->GetLinearAttenuationTerm());

		Shader::GetRotatingCubeShader()->SetUniformFloat(PointLightQuadraticUniform(i),
			Renderer::GetRendererInstance()->GetPointLight(currentPointLight++)->GetQuadraticAttenuationTerm());
	}
	

	/***************************************************************************************************
	* Setting up uniform variables, that apply only for the flashlight calculations
	****************************************************************************************************/
	Shader::GetRotatingCubeShader()->SetUniformVector3D("Spotlight.Position",
		Renderer::GetRendererInstance()->GetFlashlight()->GetPosition());

	Shader::GetRotatingCubeShader()->SetUniformVector3D("Spotlight.Direction",
		Renderer::GetRendererInstance()->GetFlashlight()->GetDirection());

	Shader::GetRotatingCubeShader()->SetUniformVector3D("Spotlight.Ambient",
		Renderer::GetRendererInstance()->GetFlashlight()->GetAmbientLighting());

	Shader::GetRotatingCubeShader()->SetUniformVector3D("Spotlight.Diffuse",
		Renderer::GetRendererInstance()->GetFlashlight()->GetDiffuseLighting());

	Shader::GetRotatingCubeShader()->SetUniformVector3D("Spotlight.Specular",
		Renderer::GetRendererInstance()->GetFlashlight()->GetSpecularLighting());
	
	Shader::GetRotatingCubeShader()->SetUniformFloat("Spotlight.Constant",
		Renderer::GetRendererInstance()->GetFlashlight()->GetConstantAttenuationTerm());

	Shader::GetRotatingCubeShader()->SetUniformFloat("Spotlight.Linear",
		Renderer::GetRendererInstance()->GetFlashlight()->GetLinearAttenuationTerm());

	Shader::GetRotatingCubeShader()->SetUniformFloat("Spotlight.Quadratic",
		Renderer::GetRendererInstance()->GetFlashlight()->GetQuadraticAttenuationTerm());

	Shader::GetRotatingCubeShader()->SetUniformFloat("Spotlight.InnerCutoff",
		Renderer::GetRendererInstance()->GetFlashlight()->GetInnerCutoff());

	Shader::GetRotatingCubeShader()->SetUniformFloat("Spotlight.OuterCutoff",
		Renderer::GetRendererInstance()->GetFlashlight()->GetOuterCutoff());


	glBindVertexArray(m_vertexArrayTag);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

void RotatingCube::Draw()
{

}









LightCube::LightCube(const glm::vec3& position, const glm::vec3& ambient, 
	const glm::vec3& diffuse,const glm::vec3& specular, float linear, float quadratic, float constant)

	:m_position(position), m_vertexArrayTag(0), m_vertexBufferTag(0),
	m_light(position, ambient, diffuse, specular, linear, quadratic, constant),
	m_color(LIGHT_CUBE_ON_COLOR),
	m_vertices
	{
		-0.25f, 0.25f, -0.25f,			
		0.25f, 0.25f, -0.25f,			
		-0.25f, -0.25f, -0.25f,		
		0.25f, -0.25f, -0.25f,			
		-0.25f, -0.25f, -0.25f,		
		0.25f, 0.25f, -0.25f,			

		0.25f, 0.25f, 0.25f,			
		-0.25f, 0.25f, 0.25f,			
		0.25f, -0.25f, 0.25f,			
		-0.25f, -0.25f, 0.25f,			
		0.25f, -0.25f, 0.25f,			
		-0.25f, 0.25f, 0.25f,			

		-0.25f, 0.25f, 0.25f,			
		-0.25f, 0.25f, -0.25f,			
		-0.25f, -0.25f, 0.25f,			
		-0.25f, -0.25f, -0.25f,		
		-0.25f, -0.25f, 0.25f,			
		-0.25f, 0.25f, -0.25f,			

		0.25f, 0.25f, -0.25f,			
		0.25f, 0.25f, 0.25f,			
		0.25f, -0.25f, -0.25f,			
		0.25f, -0.25f, 0.25f,			
		0.25f, -0.25f, -0.25f,			
		0.25f, 0.25f, 0.25f,			

		-0.25f, 0.25f, 0.25f,			
		0.25f, 0.25f, 0.25f,			
		-0.25f, 0.25f, -0.25f,			
		0.25f, 0.25f, -0.25f,			
		-0.25f, 0.25f, -0.25f,			
		0.25f, 0.25f, 0.25f,			

		-0.25f, -0.25f, -0.25f,		
		0.25f, -0.25f, -0.25f,			
		-0.25f, -0.25f, 0.25f,			
		0.25f, -0.25f, 0.25f,			
		-0.25f, -0.25f, 0.25f,			
		0.25f, -0.25f, -0.25f,			
	}
{
	glGenVertexArrays(1, &m_vertexArrayTag);
	glBindVertexArray(m_vertexArrayTag);

	glGenBuffers(1, &m_vertexBufferTag);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferTag);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	Shader::GetLightCubeShader()->Use();
	glm::mat4 perspective = Camera::GetCamera()->GetPerspective();
	Shader::GetLightCubeShader()->SetUniformMatrix4D("perspective", perspective);
	Shader::GetLightCubeShader()->SetUniformVector3D("LightColor", m_color);
}

LightCube::~LightCube()
{

}

void LightCube::OnUpdate()
{
	Shader::GetLightCubeShader()->Use();

	glm::mat4 view(1.0f);
	view = Camera::GetCamera()->GetLookAt();
	glm::mat4 model(1.0f);
	model = glm::translate(model, m_position);

	Shader::GetLightCubeShader()->SetUniformMatrix4D("view", view);
	Shader::GetLightCubeShader()->SetUniformMatrix4D("model", model);

	glBindVertexArray(m_vertexArrayTag);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

void LightCube::Draw()
{
	
}