#include "Model.h"

Model::~Model() {
    for (auto i = meshes.begin(); i != meshes.end(); i++) {
        delete* i;
    }
    meshes.clear();
}

void Model::ProcessNode(aiNode* node, const aiScene* scene) {
    std::cout << "Number of meshes: " << node->mNumMeshes << std::endl;
    // process all the node's meshes (if any)
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(ProcessMesh(mesh, scene));
    }
    // then do the same for each of its children
    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        ProcessNode(node->mChildren[i], scene);
    }
}


Mesh* Model::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    //std::vector<Texture> textures;

    //Process Vertex
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        // process vertex positions, normals and texture coordinates
        Vertex vertex;
        aiVector3D* v = &mesh->mVertices[i];
        vertex.position = { v->x, v->y, v->z };
        v = &mesh->mNormals[i];
        vertex.normal = { v->x, v->y, v->z };

        // does the mesh contain texture coordinates?
        if (mesh->mTextureCoords[0]) {
            v = &mesh->mTextureCoords[0][i];
            vertex.texCoords = { v->x, v->y };
        }
        else {
            vertex.texCoords = { 0.0f, 0.0f };
        }
        vertices.push_back(vertex);
    }
    //Process indices
    for (uint32_t i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for (uint32_t j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }

    Mesh* m = new Mesh();
    m->SetVertexBuffer(vertices);
    m->SetIndexBuffer(indices);

    return m;
}

void Model::Bind()
{
    for (auto i = meshes.begin(); i != meshes.end(); i++) {
        (*i)->Bind();
    }
}

void Model::Unbind()
{
    for (auto i = meshes.begin(); i != meshes.end(); i++) {
        (*i)->Unbind();
    }
}
