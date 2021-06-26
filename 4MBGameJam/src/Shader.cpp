#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "Util.h"

enum class ShaderType { NONE = -1, VERTEX, FRAGMENT };

Shader::Shader(const std::string filePath) : m_FilePath(filePath), m_RendererID(0)
{
    ShaderSource srcs = ParseShader(filePath);
    m_RendererID = CreateShader(srcs.vertexSrc, srcs.fragmentSrc);
}

Shader::~Shader()
{
    GLCall(glDeleteProgram(m_RendererID));
}

ShaderSource Shader::ParseShader(const std::string& filePath) {
    std::ifstream stream(filePath);
    std::string line;
    std::stringstream ss[2];

    if (!stream.good()) {
        std::cout << "Failed to retrieve the shader src from: " << filePath << std::endl;
    }

    ShaderType type = ShaderType::NONE;

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
    return { ss[0].str(), ss[1].str() };
}


unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
    //Generate and Compile shader
    GLCall(unsigned int id = glCreateShader(type));
    const char* src = source.c_str();
    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));

    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
    if (result == GL_FALSE) {
        int length;
        GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
        //TODO -> Learn about alloca (create heap in stack)
        char* msg = new char[length];
        GLCall(glGetShaderInfoLog(id, length, &length, msg));
        //TODO -> it only deal with 2 shader but it also should work with other shader
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader: " << msg << std::endl;
        GLCall(glDeleteShader(id));
        delete[] msg;
        return 0;
    }
    return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
    unsigned int program;
    GLCall(program = glCreateProgram());
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    //Delete shaders since it's already in the program
    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
}

void Shader::Bind() const
{
    GLCall(glUseProgram(m_RendererID));
}

void Shader::Unbind() const
{
    GLCall(glUseProgram(0));
}

/*
        Uniform Helpers
*/
void Shader::SetUniform4fv(const std::string& name, glm::vec4 vector)
{
    GLCall(glUniform4fv(GetUniformLocation(name),1, &vector[0]));
}

void Shader::SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4)
{
    GLCall(glUniform4f(GetUniformLocation(name), v1,v2,v3,v4));
}

void Shader::SetUniformMat4fv(const std::string name, glm::mat4 matrix)
{
    GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1,GL_FALSE,&matrix[0][0]));
}

int Shader::GetUniformLocation(const std::string& name)
{
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
        return m_UniformLocationCache[name];
    }
    GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
    if (location == -1) {
        std::cout << "Warning: uniform '" + name + "' doesn't exists." << std::endl;
    }
    m_UniformLocationCache[name] = location;
    return location;
}
