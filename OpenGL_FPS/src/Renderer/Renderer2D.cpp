#include "Renderer/Renderer2D.h"


//struct of information of what each vertex will hold
//and it will layout in GPU mem as follow
struct QuadVertex {
	glm::vec3 Position;
	glm::vec4 Color;
	glm::vec2 TexCoord;
};

struct Render2DData {

};

void Renderer2D::Init()
{

}

void Renderer2D::CleanUp()
{
}

void Renderer2D::DrawQuad(glm::mat4 transform, const glm::vec4& color)
{
}
