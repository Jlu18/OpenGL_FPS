#pragma once
#include <string>
#include <unordered_map>

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>


class Shader {
private:
	unsigned int id;

	std::unordered_map<std::string, int> m_UniformLocationCache;

	unsigned int CompileShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& name);
public:
	Shader();
	~Shader();

	void Generate(const std::string& vertexShader, const std::string& fragmentShader);

	void Bind() const;
	void UnBind() const;

	//set Uniforms
	void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4);
	void SetUniform4fv(const std::string& name, glm::vec4 vector);
	void SetUniformMat4fv(const std::string name, glm::mat4 matrix);
};