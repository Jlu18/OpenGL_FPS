#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>

#include "World.h"
#include "Shader.h"

class Renderer {
    Shader m_shader;
public:
    Renderer(const std::string shaderSrc);
    void Render(const World& w);
};

#endif