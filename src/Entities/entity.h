#pragma once

#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Helper structs and enums that hold data for complex entities
struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoordinates;
};

enum class TexType
{
	TT_DiffuseMap,
	TT_SpecularMap,
	TT_NormalMap,
	TT_HeightMap
};

struct Tex
{
	int tag;
	TexType type;
	std::string file;
};


//Virtual entity class
class Entity
{
public:
	virtual void OnUpdate() = 0;
	virtual void Draw() = 0;
};


//Takes an integer n and returns "PointLight[n].Specular
const char* PointLightSpecularUniform(unsigned int place);
//Takes an integer n and returns "PointLight[n].Diffuse
const char* PointLightDiffuseUniform(unsigned int place);
//Takes an integer n and returns "PointLight[n].Position
const char* PointLightPositionUniform(unsigned int place);
//Takes an integer n and returns "PointLight[n].Ambient
const char* PointLightAmbientUniform(unsigned int place);
//Takes an integer n and returns "PointLight[n].Constant
const char* PointLightConstantUniform(unsigned int place);
//Takes an integer n and returns "PointLight[n].Linear
const char* PointLightLinearUniform(unsigned int place);
//Takes an integer n and returns "PointLight[n].Quadratic
const char* PointLightQuadraticUniform(unsigned int place);


//Takes an integer n and returns "Material.DiffuseTex[n]
const char* DiffuseTextureUniform(unsigned int n);
//Takes an integer n and returns "Material.SpecularTex[n]
const char* SpecularTextureUniform(unsigned int n);
//Takes an integer n and returns "Material.NormalTex[n]
const char* NormalTextureUniform(unsigned int n);
//Takes an integer n and returns "Material.HeightTex[n]
const char* HeightTextureUniform(unsigned int n);