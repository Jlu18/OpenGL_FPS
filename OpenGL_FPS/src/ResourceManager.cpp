#include "ResourceManager.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <GL/glew.h>
//#include "stb_image.h"

std::map<std::string, Shader*> ResourceManager::m_shaders;
//std::map<std::string, Texture2D*>ResourceManager::m_textures;

/*
	Shader Loaders
*/
void ResourceManager::LoadShader(const std::string filePath, std::string name)
{
	m_shaders[name] = GenerateShaderData(filePath);
}

Shader* ResourceManager::GetShader(std::string name)
{
	if (HasShader(name)) {
		return m_shaders[name];
	}
	else {
		return nullptr;
	}
}

//Loader
enum class ShaderType { NONE = -1, VERTEX, FRAGMENT };

Shader* ResourceManager::GenerateShaderData(const std::string& filePath) {
	//parsing
	std::ifstream stream(filePath);
	std::string line;
	std::stringstream ss[2];

	ShaderType type = ShaderType::NONE;

	if (stream.fail() || stream.bad()) {
		std::cerr << "Failed to retrieved filePath: " << filePath << "\n";
		return nullptr;
	}

	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) {
				//set mode to vertex
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos) {
				//set mode to fragment
				type = ShaderType::FRAGMENT;
			}
		}
		else {
			if (type != ShaderType::NONE)
				ss[(int)type] << line << std::endl;
		}
	}

	//Allocate new memory for shader
	Shader* s = new Shader();

	s->Generate(ss[0].str(), ss[1].str());

	return s;
}

/*
	Texture Loaders
*/
//void ResourceManager::LoadTexture(const char* filePath, bool alpha, std::string name)
//{
//	Texture2D* texture = GenerateTextureData(filePath, alpha);
//	if (texture != nullptr) {
//		m_textures[name] = texture;
//	}
//}
//
//Texture2D* ResourceManager::GetTexture(std::string name)
//{
//	if (HasTexture(name)) {
//		return m_textures[name];
//	}
//	else {
//		return nullptr;
//	}
//}

//Texture2D* ResourceManager::GenerateTextureData(const std::string& filePath, bool alpha)
//{
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
//
//	if (data == NULL) {
//		std::cout << "failed to load texture \"" << filePath << "\": " << stbi_failure_reason() << "\n";
//		return nullptr;
//	}
//
//	Texture2D* texture = new Texture2D();
//
//	if (alpha)
//	{
//		texture->Internal_Format = GL_RGBA;
//		texture->Image_Format = GL_RGBA;
//	}
//
//	texture->Generate(width, height, data);
//
//	stbi_image_free(data);
//	return texture;
//}

/*
	Other
*/
void ResourceManager::Clear() {
	for (auto s = m_shaders.begin(); s != m_shaders.end(); s++) {
		delete s->second;
	}
	m_shaders.clear();

	//for (auto t = m_textures.begin(); t != m_textures.end(); t++) {
	//	delete t->second;
	//}
	//m_textures.clear();
}
