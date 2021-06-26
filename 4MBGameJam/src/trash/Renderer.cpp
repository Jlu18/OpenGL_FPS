#include "Renderer.h"
#include "Util.h"

Renderer::Renderer() {

}
void Renderer::Draw(Scene* scene) {
	scene.Render();
}
void Renderer::Clear() {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
	GLCall(glClearColor(0.1, 0.5, 0.1, 1.0));
}