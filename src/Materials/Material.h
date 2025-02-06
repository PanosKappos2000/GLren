#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define EMERALD_AMBIENT_VECTOR				glm::vec3(0.0215f, 0.1745f, 0.0215f)
#define JADE_AMBIENT_VECTOR					glm::vec3(0.135f, 0.2225f, 0.1575f)
#define OBSIDIAN_AMBIENT_VECTOR				glm::vec3(0.05375f, 0.05f, 0.06625f)
#define PEARL_AMBIENT_VECTOR				glm::vec3(0.25f, 0.20725f, 0.20725f)
#define RUBY_AMBIENT_VECTOR					glm::vec3(0.1745f, 0.01175f, 0.01175f)
#define TURQUOISE_AMBIENT_VECTOR			glm::vec3(0.1f, 0.18725f, 0.1745f)
#define BRASS_AMBIENT_VECTOR				glm::vec3(0.329412f, 0.223529f, 0.027451)
#define BRONZE_AMBIENT_VECTOR				glm::vec3(0.2125f, 0.1275f, 0.054)
#define CHROME_AMBIENT_VECTOR				glm::vec3(0.25f, 0.25f, 0.25f)
#define COPPER_AMBIENT_VECTOR				glm::vec3(0.19125f, 0.0735f, 0.0225f)
#define GOLD_AMBIENT_VECTOR					glm::vec3(0.24725f, 0.1995f, 0.0745f)
#define SILVER_AMBIENT_VECTOR				glm::vec3(0.19225f, 0.19225f, 0.19225f)
#define BLACK_PLASTIC_AMBIENT_VECTOR		glm::vec3(0.0f, 0.0f, 0.0f)
#define CYAN_PLASTIC_AMBIENT_VECTOR			glm::vec3(0.0f, 0.1f, 0.06f)
#define GREEN_PLASTIC_AMBIENT_VECTOR		glm::vec3(0.0f, 0.0f, 0.0f)
#define RED_PLASTIC_AMBIENT_VECTOR			glm::vec3(0.0f, 0.0f, 0.0f)
#define WHITE_PLASTIC_AMBIENT_VECTOR		glm::vec3(0.0f, 0.0f, 0.0f)
#define YELLOW_PLASTIC_AMBIENT_VECTOR		glm::vec3(0.0f, 0.0f, 0.0f)
#define BLACK_RUBBER_AMBIENT_VECTOR			glm::vec3(0.02f, 0.02f, 0.02f)
#define CYAN_RUBBER_AMBIENT_VECTOR			glm::vec3(0.0f, 0.05f, 0.05f)
#define GREEN_RUBBER_AMBIENT_VECTOR			glm::vec3(0.0f,	0.05f, 0.0f)
#define RED_RUBBER_AMBIENT_VECTOR			glm::vec3(0.05f, 0.0f, 0.0f)
#define WHITE_RUBBER_AMBIENT_VECTOR			glm::vec3(0.05f, 0.05f,	0.05f)
#define YELLOW_RUBBER_AMBIENT_VECTOR		glm::vec3(0.05f, 0.05f,	0.0f)




#define EMERALD_DIFFUSE_VECTOR				glm::vec3(0.07568f, 0.61424f, 0.07568f)
#define JADE_DIFFUSE_VECTOR					glm::vec3(0.54f, 0.89f,	0.63f)
#define OBSIDIAN_DIFFUSE_VECTOR				glm::vec3(0.18275f,	0.17f, 0.22525f)
#define PEARL_DIFFUSE_VECTOR				glm::vec3(1.0f,	0.829f,	0.829f)
#define RUBY_DIFFUSE_VECTOR					glm::vec3(0.61424f,	0.04136f, 0.04136f)
#define TURQUOISE_DIFFUSE_VECTOR			glm::vec3(0.396f, 0.74151f, 0.69102f)
#define BRASS_DIFFUSE_VECTOR				glm::vec3(0.780392f, 0.568627f, 0.113725f)
#define BRONZE_DIFFUSE_VECTOR				glm::vec3(0.714f, 0.4284f, 0.18144f)
#define CHROME_DIFFUSE_VECTOR				glm::vec3(0.4f, 0.4f, 0.4f)
#define COPPER_DIFFUSE_VECTOR				glm::vec3(0.7038f, 0.27048f, 0.0828f)
#define GOLD_DIFFUSE_VECTOR					glm::vec3(0.75164f,	0.60648f, 0.22648f)
#define SILVER_DIFFUSE_VECTOR				glm::vec3(0.50754f,	0.50754f, 0.50754f)
#define BLACK_PLASTIC_DIFFUSE_VECTOR		glm::vec3(0.01f, 0.01f,	0.01f)
#define CYAN_PLASTIC_DIFFUSE_VECTOR			glm::vec3(0.0f,	0.509803f, 0.509803f)
#define GREEN_PLASTIC_DIFFUSE_VECTOR		glm::vec3(0.1f,	0.35f, 0.1f)
#define RED_PLASTIC_DIFFUSE_VECTOR			glm::vec3(0.5f,	0.0f, 0.0f)
#define WHITE_PLASTIC_DIFFUSE_VECTOR		glm::vec3(0.55f, 0.55f,	0.55f)
#define YELLOW_PLASTIC_DIFFUSE_VECTOR		glm::vec3(0.5f,	0.5f, 0.0f)
#define BLACK_RUBBER_DIFFUSE_VECTOR			glm::vec3(0.01f, 0.01f,	0.01f)
#define CYAN_RUBBER_DIFFUSE_VECTOR			glm::vec3(0.4f,	0.5f, 0.5f)
#define GREEN_RUBBER_DIFFUSE_VECTOR			glm::vec3(0.4f, 0.5, 0.4f)
#define RED_RUBBER_DIFFUSE_VECTOR			glm::vec3(0.5f,	0.4f, 0.4)
#define WHITE_RUBBER_DIFFUSE_VECTOR			glm::vec3(0.5f,	0.5f, 0.5f)
#define YELLOW_RUBBER_DIFFUSE_VECTOR		glm::vec3(0.5f,	0.5f, 0.4f)




#define EMERALD_SPECULAR_VECTOR				glm::vec3(0.633f, 0.727811f, 0.633)
#define JADE_SPECULAR_VECTOR				glm::vec3(0.316228f, 0.316228f, 0.316228)
#define OBSIDIAN_SPECULAR_VECTOR			glm::vec3(0.332741f, 0.328634f,	0.346435f)
#define PEARL_SPECULAR_VECTOR				glm::vec3(0.296648f, 0.296648f,	0.296648f)
#define RUBY_SPECULAR_VECTOR				glm::vec3(0.727811f, 0.626959f,	0.626959f)
#define TURQUOISE_SPECULAR_VECTOR			glm::vec3(0.297254f, 0.30829f, 0.306678f)
#define BRASS_SPECULAR_VECTOR				glm::vec3(0.992157f, 0.941176f,	0.807843f)
#define BRONZE_SPECULAR_VECTOR				glm::vec3(0.393548f, 0.271906f,	0.166721f)
#define CHROME_SPECULAR_VECTOR				glm::vec3(0.774597f, 0.774597f,	0.774597f)
#define COPPER_SPECULAR_VECTOR				glm::vec3(0.256777f, 0.137622f,	0.086014f)
#define GOLD_SPECULAR_VECTOR				glm::vec3(0.628281f, 0.555802f,	0.366065f)
#define SILVER_SPECULAR_VECTOR				glm::vec3(0.508273f, 0.508273f,	0.508273f)
#define BLACK_PLASTIC_SPECULAR_VECTOR		glm::vec3(0.50f, 0.50f,	0.50f)
#define CYAN_PLASTIC_SPECULAR_VECTOR		glm::vec3(0.501960f, 0.501960f, 0.501960f)
#define GREEN_PLASTIC_SPECULAR_VECTOR		glm::vec3(0.45f, 0.55f,	0.45f)
#define RED_PLASTIC_SPECULAR_VECTOR			glm::vec3(0.7f,	0.6f, 0.6f)
#define WHITE_PLASTIC_SPECULAR_VECTOR		glm::vec3(0.70f, 0.70f,	0.70f)
#define YELLOW_PLASTIC_SPECULAR_VECTOR		glm::vec3(0.60f, 0.60f,	0.50f)
#define BLACK_RUBBER_SPECULAR_VECTOR		glm::vec3(0.4f,	0.4f, 0.4f)
#define CYAN_RUBBER_SPECULAR_VECTOR			glm::vec3(0.04f, 0.7f, 0.7f)
#define GREEN_RUBBER_SPECULAR_VECTOR		glm::vec3(0.04f, 0.7f, 0.04)
#define RED_RUBBER_SPECULAR_VECTOR			glm::vec3(0.7f,	0.04f, 0.04f)
#define WHITE_RUBBER_SPECULAR_VECTOR		glm::vec3(0.7f,	0.7f, 0.7f)
#define YELLOW_RUBBER_SPECULAR_VECTOR		glm::vec3(0.7f,	0.7f, 0.04f)




#define EMERALD_SHININESS				0.6f	
#define JADE_SHININESS					0.1f
#define OBSIDIAN_SHININESS				0.3f
#define PEARL_SHININESS					0.088f
#define RUBY_SHININESS					0.6f
#define TURQUOISE_SHININESS				0.1f
#define BRASS_SHININESS					0.217948f
#define BRONZE_SHININESS				0.2f
#define CHROME_SHININESS				0.6f
#define COPPER_SHININESS				0.1f
#define GOLD_SHININESS					0.4f
#define SILVER_SHININESS				0.4f
#define BLACK_PLASTIC_SHININESS			0.25f
#define CYAN_PLASTIC_SHININESS			0.25f
#define GREEN_PLASTIC_SHININESS			0.25f
#define RED_PLASTIC_SHININESS			0.25f
#define WHITE_PLASTIC_SHININESS			0.25f
#define YELLOW_PLASTIC_SHININESS		0.25f
#define BLACK_RUBBER_SHININESS			0.078125f
#define CYAN_RUBBER_SHININESS			0.078125f
#define GREEN_RUBBER_SHININESS			0.078125f
#define RED_RUBBER_SHININESS			0.078125f
#define WHITE_RUBBER_SHININESS			0.078125f
#define YELLOW_RUBBER_SHININESS			0.078125f

enum class MaterialType
{
	MT_Emerald,
	MT_Jade,
	MT_Obsidian,
	MT_Pearl,
	MT_Ruby,
	MT_Turquoise,
	MT_Brass,
	MT_Bronze,
	MT_Chrome,
	MT_Copper,
	MT_Gold,
	MT_Silver,
	MT_BlackPlastic,
	MT_CyanPlastic,
	MT_GreenPlastic,
	MT_RedPlastic,
	MT_WhitePlastic,
	MT_YellowPlastic,
	MT_BlackRubber,
	MT_CyanRubber,
	MT_GreenRubber,
	MT_RedRubber,
	MT_WhiteRubber,
	MT_YellowRubber
};

const glm::vec3& GetMaterialAmbientVector(MaterialType type);
const glm::vec3& GetMaterialDiffuseVector(MaterialType type);
const glm::vec3& GetMaterialSpecularVector(MaterialType type);
float GetMaterialShininess(MaterialType type);

struct Material
{
public:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;

	Material(MaterialType type);
	Material();
	~Material();
};