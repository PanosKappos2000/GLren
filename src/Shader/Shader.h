#pragma once

#include <string>
#include <fstream>
#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define ROTATING_CUBE_SHADER_FILEPATH				"Shaders/CubeShader.shader"
#define LIGHT_CUBE_SHADER_FILEPATH					"Shaders/LightCubeShader.shader"
#define MESH_SHADER_FILEPATH						"Shaders/BasicMesh.shader"
#define VEGETATION_SHADER_FILEPATH					"Shaders/Vegetation.shader"

enum class ShaderType
{
	ST_Vertex,
	ST_Fragment,
};

class Shader
{
private:
	int m_tag;
	static Shader* s_rotatingCubeShader;
	static Shader* s_lightCubeShader;
	static Shader* s_meshShader;
	static Shader* s_vegetationShader;
public:
	Shader(std::string& shaderFilepath);
	~Shader();
	static void Init();
	static void DeInit();

	inline int GetTag() const { return m_tag; }

	inline void Use() { glUseProgram(m_tag); }

	inline void SetUniformMatrix4D(const char* varName, const glm::mat4& var)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_tag, varName), 1, GL_FALSE, glm::value_ptr(var));
	}

	inline void SetUniformMatrix3D(const char* varName, const glm::mat3& var)
	{
		glUniformMatrix3fv(glGetUniformLocation(m_tag, varName), 1, GL_FALSE, glm::value_ptr(var));
	}

	inline void SetUniformVector3D(const char* varName, const glm::vec3& var)
	{
		glUniform3fv(glGetUniformLocation(m_tag, varName), 1, glm::value_ptr(var));
	}

	inline void SetUniformFloat(const char* varName, float var)
	{
		glUniform1f(glGetUniformLocation(m_tag, varName), var);
	}

	inline void SetUniformInt(const char* varName, int var)
	{
		glUniform1i(glGetUniformLocation(m_tag, varName), var);
	}

	inline void SetUniformUnsignedInt(const char* varName, unsigned int var)
	{
		glUniform1ui(glGetUniformLocation(m_tag, varName), var);
	}

	static void CreateRotatingCubeShader();
	static Shader* GetRotatingCubeShader() { return s_rotatingCubeShader; }

	static void CreateLightCubeShader();
	static Shader* GetLightCubeShader() { return s_lightCubeShader; }

	static void CreateMeshShader();
	static Shader* GetMeshShader() { return s_meshShader; }

	static void CreateVegetationShader();
	static Shader* GetVegetationShader() { return s_vegetationShader; }
};