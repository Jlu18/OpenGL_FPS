#pragma once
#include <string>
#include <unordered_map>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

struct ShaderSource {
	std::string vertexSrc;
	std::string fragmentSrc;
};

class Shader {
private:
	unsigned int m_RendererID;
	//debug purpose
	std::string m_FilePath;
	std::unordered_map<std::string, int> m_UniformLocationCache;

	ShaderSource ParseShader(const std::string& filePath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	int GetUniformLocation(const std::string& name);
public:
	Shader(const std::string filePath);
	~Shader();
	void Bind() const;
	void Unbind() const;

	//set Uniforms
	void SetUniform4fv(const std::string&name, glm::vec4 vector);
	void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4);
	void SetUniformMat4fv(const std::string name, glm::mat4 matrix);
};