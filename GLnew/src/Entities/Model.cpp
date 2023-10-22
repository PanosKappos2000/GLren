#include "Model.h"
#include "Texture/texture.h"

Model::Model(const std::string& filepath)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ASSIMP::ERROR: " << importer.GetErrorString() << '\n';
		__debugbreak();
	}
	m_directory = filepath.substr(0, filepath.find_last_of('/'));

	ProcessNode(scene->mRootNode, scene);
}

Model::~Model()
{
	
}

void Model::ProcessNode(aiNode* node, const aiScene* scene)
{
	for (unsigned int i = 0; i < node->mNumMeshes; ++i)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		m_meshes.emplace_back(ProcessMesh(mesh, scene));
	}
	for (unsigned int i = 0; i < node->mNumChildren; ++i)
	{
		ProcessNode(node->mChildren[i], scene);
	}
}

Mesh Model::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Tex> textures;

	for (unsigned int i = 0; i < mesh->mNumVertices; ++i)
	{
		Vertex vertex;

		vertex.position.x = mesh->mVertices[i].x;
		vertex.position.y = mesh->mVertices[i].y;
		vertex.position.z = mesh->mVertices[i].z;

		if (mesh->HasNormals())
		{
			vertex.normal.x = mesh->mNormals[i].x;
			vertex.normal.y = mesh->mNormals[i].y;
			vertex.normal.z = mesh->mNormals[i].z;
		}

		if (mesh->mTextureCoords[0])
		{
			vertex.texCoordinates.x = mesh->mTextureCoords[0][i].x;
			vertex.texCoordinates.y = mesh->mTextureCoords[0][i].y;
		}
		else
		{
			vertex.texCoordinates = glm::vec2(0.0f, 0.0f);
		}
		vertices.emplace_back(vertex);
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; ++i)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; ++j)
		{
			indices.emplace_back(face.mIndices[j]);
		}
	}

	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		std::vector<Tex>diffuseMaps;
		LoadMaterialTextures(material, aiTextureType_DIFFUSE,
			TexType::TT_DiffuseMap, diffuseMaps);
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		std::vector<Tex>specularMaps;
		LoadMaterialTextures(material, aiTextureType_SPECULAR,
			TexType::TT_SpecularMap, specularMaps);
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		std::vector<Tex>normalMaps;
		LoadMaterialTextures(material, aiTextureType_NORMALS,
			TexType::TT_NormalMap,normalMaps);
		textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
		std::vector<Tex>heightMaps;
		LoadMaterialTextures(material, aiTextureType_HEIGHT,
			TexType::TT_HeightMap, heightMaps);
		textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
	}

	return Mesh(vertices, textures, indices);
}

void Model::LoadMaterialTextures(aiMaterial* mat, aiTextureType type, TexType tex,
	std::vector<Tex>& textures)
{
	for (unsigned int i = 0; i < mat->GetTextureCount(type); ++i)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		bool skip = false;
		for (unsigned int j = 0; j < m_loadedTextures.size(); ++j)
		{
			if (std::strcmp(m_loadedTextures[j].file.data(), str.C_Str()) == 0)
			{
				textures.emplace_back(m_loadedTextures[j]);
				skip = true;
				break;
			}
		}
		if (!skip)
		{
			std::string file = str.C_Str();
			std::string filepath = m_directory + '/' + file;
			Tex texture;
			texture.tag = TextureFromFile(filepath);
			texture.type = tex;
			texture.file = str.C_Str();
			m_loadedTextures.emplace_back(texture);
			textures.emplace_back(texture);
		}
	}
}

void Model::OnUpdate()
{
	for (unsigned int i = 0; i < m_meshes.size(); ++i)
	{
		m_meshes[i].OnUpdate();
	}
}

void Model::Draw()
{

}