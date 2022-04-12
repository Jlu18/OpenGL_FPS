#pragma once

#include <assimp/scene.h>
#include "OpenGL/Mesh.h"

class Model {
	std::vector<Mesh*>meshes;

	Mesh* ProcessMesh(aiMesh* mesh, const aiScene* scene);
public:
	Model() = default;
	~Model();

	void ProcessNode(aiNode* node, const aiScene* scene);

	void Bind();
	void Unbind();
};