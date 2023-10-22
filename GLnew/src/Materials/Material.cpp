#include "Material.h"

Material::Material(MaterialType type)
	:ambient(GetMaterialAmbientVector(type)), 
	diffuse(GetMaterialDiffuseVector(type)),
	specular(GetMaterialSpecularVector(type)),
	shininess(GetMaterialShininess(type))
{

}

Material::Material()
	:ambient(glm::vec3(1.0f)),
	diffuse(glm::vec3(1.0f)),
	specular(glm::vec3(1.0f)),
	shininess(1.0f)
{

}

Material::~Material()
{

}







const glm::vec3& GetMaterialAmbientVector(MaterialType type)
{
	switch (type)
	{
		case MaterialType::MT_Emerald:
		{
			return EMERALD_AMBIENT_VECTOR;
		}
		case MaterialType::MT_Jade:
		{
			return JADE_AMBIENT_VECTOR;
		}
		case MaterialType::MT_Obsidian:
		{
			return OBSIDIAN_AMBIENT_VECTOR;
		}
		case MaterialType::MT_Pearl:
		{
			return PEARL_AMBIENT_VECTOR;
		}
		case MaterialType::MT_Ruby:
		{
			return RUBY_AMBIENT_VECTOR;
		}
		case MaterialType::MT_Turquoise:
		{
			return TURQUOISE_AMBIENT_VECTOR;
		}
		case MaterialType::MT_Brass:
		{
			return BRASS_AMBIENT_VECTOR;
		}
		case MaterialType::MT_Bronze:
		{
			return BRONZE_AMBIENT_VECTOR;
		}
		case MaterialType::MT_Chrome:
		{
			return CHROME_AMBIENT_VECTOR;
		}
		case MaterialType::MT_Copper:
		{
			return COPPER_AMBIENT_VECTOR;
		}
		case MaterialType::MT_Gold:
		{
			return GOLD_AMBIENT_VECTOR;
		}
		case MaterialType::MT_Silver:
		{
			return SILVER_AMBIENT_VECTOR;
		}
		case MaterialType::MT_BlackPlastic:
		{
			return BLACK_PLASTIC_AMBIENT_VECTOR;
		}
		case MaterialType::MT_CyanPlastic:
		{
			return CYAN_PLASTIC_AMBIENT_VECTOR;
		}
		case MaterialType::MT_GreenPlastic:
		{
			return GREEN_PLASTIC_AMBIENT_VECTOR;
		}
		case MaterialType::MT_RedPlastic:
		{
			return RED_PLASTIC_AMBIENT_VECTOR;
		}
		case MaterialType::MT_WhitePlastic:
		{
			return WHITE_PLASTIC_AMBIENT_VECTOR;
		}
		case MaterialType::MT_YellowPlastic:
		{
			return YELLOW_PLASTIC_AMBIENT_VECTOR;
		}
		case MaterialType::MT_BlackRubber:
		{
			return BLACK_RUBBER_AMBIENT_VECTOR;
		}
		case MaterialType::MT_CyanRubber:
		{
			return CYAN_RUBBER_AMBIENT_VECTOR;
		}
		case MaterialType::MT_GreenRubber:
		{
			return GREEN_RUBBER_AMBIENT_VECTOR;
		}
		case MaterialType::MT_RedRubber:
		{
			return RED_RUBBER_AMBIENT_VECTOR;
		}
		case MaterialType::MT_WhiteRubber:
		{
			return WHITE_RUBBER_AMBIENT_VECTOR;
		}
		case MaterialType::MT_YellowRubber:
		{
			return YELLOW_RUBBER_AMBIENT_VECTOR;
		}
	}
}

const glm::vec3& GetMaterialDiffuseVector(MaterialType type)
{
	switch (type)
	{
		case MaterialType::MT_Emerald:
		{
			return EMERALD_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_Jade:
		{
			return JADE_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_Obsidian:
		{
			return OBSIDIAN_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_Pearl:
		{
			return PEARL_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_Ruby:
		{
			return RUBY_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_Turquoise:
		{
			return TURQUOISE_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_Brass:
		{
			return BRASS_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_Bronze:
		{
			return BRONZE_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_Chrome:
		{
			return CHROME_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_Copper:
		{
			return COPPER_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_Gold:
		{
			return GOLD_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_Silver:
		{
			return SILVER_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_BlackPlastic:
		{
			return BLACK_PLASTIC_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_CyanPlastic:
		{
			return CYAN_PLASTIC_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_GreenPlastic:
		{
			return GREEN_PLASTIC_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_RedPlastic:
		{
			return RED_PLASTIC_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_WhitePlastic:
		{
			return WHITE_PLASTIC_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_YellowPlastic:
		{
			return YELLOW_PLASTIC_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_BlackRubber:
		{
			return BLACK_RUBBER_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_CyanRubber:
		{
			return CYAN_RUBBER_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_GreenRubber:
		{
			return GREEN_RUBBER_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_RedRubber:
		{
			return RED_RUBBER_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_WhiteRubber:
		{
			return WHITE_RUBBER_DIFFUSE_VECTOR;
		}
		case MaterialType::MT_YellowRubber:
		{
			return YELLOW_RUBBER_DIFFUSE_VECTOR;
		}
	}
}

const glm::vec3& GetMaterialSpecularVector(MaterialType type)
{
	switch (type)
	{
		case MaterialType::MT_Emerald:
		{
			return EMERALD_SPECULAR_VECTOR;
		}
		case MaterialType::MT_Jade:
		{
			return JADE_SPECULAR_VECTOR;
		}
		case MaterialType::MT_Obsidian:
		{
			return OBSIDIAN_SPECULAR_VECTOR;
		}
		case MaterialType::MT_Pearl:
		{
			return PEARL_SPECULAR_VECTOR;
		}
		case MaterialType::MT_Ruby:
		{
			return RUBY_SPECULAR_VECTOR;
		}
		case MaterialType::MT_Turquoise:
		{
			return TURQUOISE_SPECULAR_VECTOR;
		}
		case MaterialType::MT_Brass:
		{
			return BRASS_SPECULAR_VECTOR;
		}
		case MaterialType::MT_Bronze:
		{
			return BRONZE_SPECULAR_VECTOR;
		}
		case MaterialType::MT_Chrome:
		{
			return CHROME_SPECULAR_VECTOR;
		}
		case MaterialType::MT_Copper:
		{
			return COPPER_SPECULAR_VECTOR;
		}
		case MaterialType::MT_Gold:
		{
			return GOLD_SPECULAR_VECTOR;
		}
		case MaterialType::MT_Silver:
		{
			return SILVER_SPECULAR_VECTOR;
		}
		case MaterialType::MT_BlackPlastic:
		{
			return BLACK_PLASTIC_SPECULAR_VECTOR;
		}
		case MaterialType::MT_CyanPlastic:
		{
			return CYAN_PLASTIC_SPECULAR_VECTOR;
		}
		case MaterialType::MT_GreenPlastic:
		{
			return GREEN_PLASTIC_SPECULAR_VECTOR;
		}
		case MaterialType::MT_RedPlastic:
		{
			return RED_PLASTIC_SPECULAR_VECTOR;
		}
		case MaterialType::MT_WhitePlastic:
		{
			return WHITE_PLASTIC_SPECULAR_VECTOR;
		}
		case MaterialType::MT_YellowPlastic:
		{
			return YELLOW_PLASTIC_SPECULAR_VECTOR;
		}
		case MaterialType::MT_BlackRubber:
		{
			return BLACK_RUBBER_SPECULAR_VECTOR;
		}
		case MaterialType::MT_CyanRubber:
		{
			return CYAN_RUBBER_SPECULAR_VECTOR;
		}
		case MaterialType::MT_GreenRubber:
		{
			return GREEN_RUBBER_SPECULAR_VECTOR;
		}
		case MaterialType::MT_RedRubber:
		{
			return RED_RUBBER_SPECULAR_VECTOR;
		}
		case MaterialType::MT_WhiteRubber:
		{
			return WHITE_RUBBER_SPECULAR_VECTOR;
		}
		case MaterialType::MT_YellowRubber:
		{
			return YELLOW_RUBBER_SPECULAR_VECTOR;
		}
	}
}

float GetMaterialShininess(MaterialType type)
{
	switch (type)
	{
		case MaterialType::MT_Emerald:
		{
			return EMERALD_SHININESS;
		}
		case MaterialType::MT_Jade:
		{
			return JADE_SHININESS;
		}
		case MaterialType::MT_Obsidian:
		{
			return OBSIDIAN_SHININESS;
		}
		case MaterialType::MT_Pearl:
		{
			return PEARL_SHININESS;
		}
		case MaterialType::MT_Ruby:
		{
			return RUBY_SHININESS;
		}
		case MaterialType::MT_Turquoise:
		{
			return TURQUOISE_SHININESS;
		}
		case MaterialType::MT_Brass:
		{
			return BRASS_SHININESS;
		}
		case MaterialType::MT_Bronze:
		{
			return BRONZE_SHININESS;
		}
		case MaterialType::MT_Chrome:
		{
			return CHROME_SHININESS;
		}
		case MaterialType::MT_Copper:
		{
			return COPPER_SHININESS;
		}
		case MaterialType::MT_Gold:
		{
			return GOLD_SHININESS;
		}
		case MaterialType::MT_Silver:
		{
			return SILVER_SHININESS;
		}
		case MaterialType::MT_BlackPlastic:
		{
			return BLACK_PLASTIC_SHININESS;
		}
		case MaterialType::MT_CyanPlastic:
		{
			return CYAN_PLASTIC_SHININESS;
		}
		case MaterialType::MT_GreenPlastic:
		{
			return GREEN_PLASTIC_SHININESS;
		}
		case MaterialType::MT_RedPlastic:
		{
			return RED_PLASTIC_SHININESS;
		}
		case MaterialType::MT_WhitePlastic:
		{
			return WHITE_PLASTIC_SHININESS;
		}
		case MaterialType::MT_YellowPlastic:
		{
			return YELLOW_PLASTIC_SHININESS;
		}
		case MaterialType::MT_BlackRubber:
		{
			return BLACK_RUBBER_SHININESS;
		}
		case MaterialType::MT_CyanRubber:
		{
			return CYAN_RUBBER_SHININESS;
		}
		case MaterialType::MT_GreenRubber:
		{
			return GREEN_RUBBER_SHININESS;
		}
		case MaterialType::MT_RedRubber:
		{
			return RED_RUBBER_SHININESS;
		}
		case MaterialType::MT_WhiteRubber:
		{
			return WHITE_RUBBER_SHININESS;
		}
		case MaterialType::MT_YellowRubber:
		{
			return YELLOW_RUBBER_SHININESS;
		}
	}
}