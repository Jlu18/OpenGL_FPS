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
	void SetVec3f(const std::string& name, const glm::vec3& vector);
	void SetVec4f(const std::string& name, const glm::vec4& vector);
	void SetMat4f(const std::string& name, const glm::mat4& matrix);
};