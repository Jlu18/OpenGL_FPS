#pragma once

#include <OpenGL/Mesh.h>
#include <assimp/scene.h>

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