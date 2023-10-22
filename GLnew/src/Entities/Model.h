#pragma once

#include "Mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model : public Entity
{
private:
	std::vector<Mesh> m_meshes;
	std::vector<Tex> m_loadedTextures;
	std::string m_directory;
public:
	Model(const std::string& filepath);
	~Model();

	void OnUpdate() override;
	void Draw() override;
private:
	void ProcessNode(aiNode* node, const aiScene* scene);
	Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
	void LoadMaterialTextures(aiMaterial* mat, aiTextureType type, TexType tex, std::vector<Tex>& texture);
};