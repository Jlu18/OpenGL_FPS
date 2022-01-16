#pragma once

#include <map>
#include <string>

#include "Shader.h"
#include "Texture2D.h"

/*
    Resource Management Class
      Reference from learnopengl
      https://learnopengl.com/In-Practice/2D-Game/Setting-up
      https://github.com/JoeyDeVries/LearnOpenGL/blob/master/src/7.in_practice/3.2d_game/0.full_source/resource_manager.h
*/
class ResourceManager {
public:
    // resource storage
    static std::map<std::string, Shader*> m_shaders;
    static std::map<std::string, Texture2D*> m_textures;
    //shader
    static Shader* LoadShader(const std::string filePath, std::string name);
    static Shader* GetShader(std::string name);
    //texture
    static Texture2D* LoadTexture(const char* file, bool alpha, std::string name);
    static Texture2D* GetTexture(std::string name);


    inline static bool HasTexture(std::string name) { return m_textures.find(name) != m_textures.end(); };
    inline static bool HasShader(std::string name) { return m_shaders.find(name) != m_shaders.end(); };

    static void Clear();

private:
    static Texture2D* GenerateTextureData(const std::string& filePath, bool alpha);
    static Shader* GenerateShaderData(const std::string& filePath);
    // private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
    ResourceManager() { }
};


/*
    TODO: Safeguard for when shader or texture are failed to load
*/