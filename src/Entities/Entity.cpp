#include "entity.h"


void Entity::OnUpdate()
{

}
	
void Entity::Draw()
{
	
}




/**********************************************************************
* Functions for returning the correct point light uniform string
***********************************************************************/
const char* PointLightSpecularUniform(unsigned int place)
{
	switch (place)
	{
		case 0:
		{
			return "PointLight[0].Specular";
		}
		case 1:
		{
			return "PointLight[1].Specular";
		}
		case 2:
		{
			return "PointLight[2].Specular";
		}
		case 3:
		{
			return "PointLight[3].Specular";
		}
		case 4:
		{
			return "PointLight[4].Specular";
		}
		case 5:
		{
			return "PointLight[5].Specular";
		}
		case 6:
		{
			return "PointLight[6].Specular";
		}
		case 7:
		{
			return "PointLight[7].Specular";
		}
		case 8:
		{
			return "PointLight[8].Specular";
		}
		case 9:
		{
			return "PointLight[9].Specular";
		}
		default:
		{
			return "NoUniform";
		}
	}
}

const char* PointLightDiffuseUniform(unsigned int place)
{
	switch (place)
	{
		case 0:
		{
			return "PointLight[0].Diffuse";
		}
		case 1:
		{
			return "PointLight[1].Diffuse";
		}
		case 2:
		{
			return "PointLight[2].Diffuse";
		}
		case 3:
		{
			return "PointLight[3].Diffuse";
		}
		case 4:
		{
			return "PointLight[4].Diffuse";
		}
		case 5:
		{
			return "PointLight[5].Diffuse";
		}
		case 6:
		{
			return "PointLight[6].Diffuse";
		}
		case 7:
		{
			return "PointLight[7].Diffuse";
		}
		case 8:
		{
			return "PointLight[8].Diffuse";
		}
		case 9:
		{
			return "PointLight[9].Diffuse";
		}
		default:
		{
			return "NoUniform";
		}
	}
}

const char* PointLightPositionUniform(unsigned int place)
{
	switch (place)
	{
		case 0:
		{
			return "PointLight[0].Position";
		}
		case 1:
		{
			return "PointLight[1].Position";
		}
		case 2:
		{
			return "PointLight[2].Position";
		}
		case 3:
		{
			return "PointLight[3].Position";
		}
		case 4:
		{
			return "PointLight[4].Position";
		}
		case 5:
		{
			return "PointLight[5].Position";
		}
		case 6:
		{
			return "PointLight[6].Position";
		}
		case 7:
		{
			return "PointLight[7].Position";
		}
		case 8:
		{
			return "PointLight[8].Position";
		}
		case 9:
		{
			return "PointLight[9].Position";
		}
		default:
		{
			return "NoUniform";
		}
	}
}

const char* PointLightAmbientUniform(unsigned int place)
{
	switch (place)
	{
		case 0:
		{
			return "PointLight[0].Ambient";
		}
		case 1:
		{
			return "PointLight[1].Ambient";
		}
		case 2:
		{
			return "PointLight[2].Ambient";
		}
		case 3:
		{
			return "PointLight[3].Ambient";
		}
		case 4:
		{
			return "PointLight[4].Ambient";
		}
		case 5:
		{
			return "PointLight[5].Ambient";
		}
		case 6:
		{
			return "PointLight[6].Ambient";
		}
		case 7:
		{
			return "PointLight[7].Ambient";
		}
		case 8:
		{
			return "PointLight[8].Ambient";
		}
		case 9:
		{
			return "PointLight[9].Ambient";
		}
		default:
		{
			return "NoUniform";
		}
	}
}

const char* PointLightConstantUniform(unsigned int place)
{
	switch (place)
	{
		case 0:
		{
			return "PointLight[0].Constant";
		}
		case 1:
		{
			return "PointLight[1].Constant";
		}
		case 2:
		{
			return "PointLight[2].Constant";
		}
		case 3:
		{
			return "PointLight[3].Constant";
		}
		case 4:
		{
			return "PointLight[4].Constant";
		}
		case 5:
		{
			return "PointLight[5].Constant";
		}
		case 6:
		{
			return "PointLight[6].Constant";
		}
		case 7:
		{
			return "PointLight[7].Constant";
		}
		case 8:
		{
			return "PointLight[8].Constant";
		}
		case 9:
		{
			return "PointLight[9].Constant";
		}
		default:
		{
			return "NoUniform";
		}
	}
}

const char* PointLightLinearUniform(unsigned int place)
{
	switch (place)
	{
		case 0:
		{
			return "PointLight[0].Linear";
		}
		case 1:
		{
			return "PointLight[1].Linear";
		}
		case 2:
		{
			return "PointLight[2].Linear";
		}
		case 3:
		{
			return "PointLight[3].Linear";
		}
		case 4:
		{
			return "PointLight[4].Linear";
		}
		case 5:
		{
			return "PointLight[5].Linear";
		}
		case 6:
		{
			return "PointLight[6].Linear";
		}
		case 7:
		{
			return "PointLight[7].Linear";
		}
		case 8:
		{
			return "PointLight[8].Linear";
		}
		case 9:
		{
			return "PointLight[9].Linear";
		}
		default:
		{
			return "NoUniform";
		}
	}
}

const char* PointLightQuadraticUniform(unsigned int place)
{
	switch (place)
	{
		case 0:
		{
			return "PointLight[0].Quadratic";
		}
		case 1:
		{
			return "PointLight[1].Quadratic";
		}
		case 2:
		{
			return "PointLight[2].Quadratic";
		}
		case 3:
		{
			return "PointLight[3].Quadratic";
		}
		case 4:
		{
			return "PointLight[4].Quadratic";
		}
		case 5:
		{
			return "PointLight[5].Quadratic";
		}
		case 6:
		{
			return "PointLight[6].Quadratic";
		}
		case 7:
		{
			return "PointLight[7].Quadratic";
		}
		case 8:
		{
			return "PointLight[8].Quadratic";
		}
		case 9:
		{
			return "PointLight[9].Quadratic";
		}
		default:
		{
			return "NoUniform";
		}
	}
}




/**********************************************************************
* Functions for returning the correct texture uniform string
***********************************************************************/
const char* DiffuseTextureUniform(unsigned int n)
{
	switch (n)
	{
		case 0:
		{
			return "Material.DiffuseTex[0]";
		}
		case 1:
		{
			return "Material.DiffuseTex[1]";
		}
		case 2:
		{
			return "Material.DiffuseTex[2]";
		}
		case 3:
		{
			return "Material.DiffuseTex[3]";
		}
		case 4:
		{
			return "Material.DiffuseTex[4]";
		}
		case 5:
		{
			return "Material.DiffuseTex[5]";
		}
		case 6:
		{
			return "Material.DiffuseTex[6]";
		}
		case 7:
		{
			return "Material.DiffuseTex[7]";
		}
		case 8:
		{
			return "Material.DiffuseTex[8]";
		}
		case 9:
		{
			return "Material.DiffuseTex[9]";
		}
		case 10:
		{
			return "Material.DiffuseTex[10]";
		}
		case 11:
		{
			return "Material.DiffuseTex[11]";
		}
		default:
		{
			return "No Uniform";
		}
	}
}

const char* SpecularTextureUniform(unsigned int n)
{
	switch (n)
	{
		case 0:
		{
			return "Material.SpecularTex[0]";
		}
		case 1:
		{
			return "Material.SpecularTex[1]";
		}
		case 2:
		{
			return "Material.SpecularTex[2]";
		}
		case 3:
		{
			return "Material.SpecularTex[3]";
		}
		case 4:
		{
			return "Material.SpecularTex[4]";
		}
		case 5:
		{
			return "Material.SpecularTex[5]";
		}
		case 6:
		{
			return "Material.SpecularTex[6]";
		}
		case 7:
		{
			return "Material.SpecularTex[7]";
		}
		case 8:
		{
			return "Material.SpecularTex[8]";
		}
		case 9:
		{
			return "Material.SpecularTex[9]";
		}
		case 10:
		{
			return "Material.SpecularTex[10]";
		}
		case 11:
		{
			return "Material.SpecularTex[11]";
		}
		default:
		{
			return "No Uniform";
		}
	}
}

const char* NormalTextureUniform(unsigned int n)
{
	switch (n)
	{
		case 0:
		{
			return "Material.NormalTex[0]";
		}
		case 1:
		{
			return "Material.NormalTex[1]";
		}
		case 2:
		{
			return "Material.NormalTex[2]";
		}
		case 3:
		{
			return "Material.NormalTex[3]";
		}
		case 4:
		{
			return "Material.NormalTex[4]";
		}
		case 5:
		{
			return "Material.NormalTex[5]";
		}
		case 6:
		{
			return "Material.NormalTex[6]";
		}
		case 7:
		{
			return "Material.NormalTex[7]";
		}
		case 8:
		{
			return "Material.NormalTex[8]";
		}
		case 9:
		{
			return "Material.NormalTex[9]";
		}
		case 10:
		{
			return "Material.NormalTex[10]";
		}
		case 11:
		{
			return "Material.NormalTex[11]";
		}
		default:
		{
			return "No Uniform";
		}
	}
}

const char* HeightTextureUniform(unsigned int n)
{
	switch (n)
	{
		case 0:
		{
			return "Material.HeightTex[0]";
		}
		case 1:
		{
			return "Material.HeightTex[1]";
		}
		case 2:
		{
			return "Material.HeightTex[2]";
		}
		case 3:
		{
			return "Material.HeightTex[3]";
		}
		case 4:
		{
			return "Material.HeightTex[4]";
		}
		case 5:
		{
			return "Material.HeightTex[5]";
		}
		case 6:
		{
			return "Material.HeightTex[6]";
		}
		case 7:
		{
			return "Material.HeightTex[7]";
		}
		case 8:
		{
			return "Material.HeightTex[8]";
		}
		case 9:
		{
			return "Material.HeightTex[9]";
		}
		case 10:
		{
			return "Material.HeightTex[10]";
		}
		case 11:
		{
			return "Material.HeightTex[11]";
		}
		default:
		{
			return "No Uniform";
		}
	}
}