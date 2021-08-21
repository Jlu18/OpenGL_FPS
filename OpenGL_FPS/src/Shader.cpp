#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "util.h"

/*
    Reference from Shader video from TheCherno
*/
enum class ShaderType { NONE = -1, VERTEX, FRAGMENT };

Shader::Shader()
{
    GLCall(id = glCreateProgram());
}

Shader::~Shader()
{
    GLCall(glDeleteProgram(id));
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
    //Generate and Compile shader
    GLCall(unsigned int s_id = glCreateShader(type));
    const char* src = source.c_str();
    GLCall(glShaderSource(s_id, 1, &src, nullptr));
    GLCall(glCompileShader(s_id));

    int result;
    GLCall(glGetShaderiv(s_id, GL_COMPILE_STATUS, &result));
    if (result == GL_FALSE) {
        int length;
        GLCall(glGetShaderiv(s_id, GL_INFO_LOG_LENGTH, &length));
        //TODO -> Learn about alloca (create heap in stack)
        char* msg = new char[length];
        GLCall(glGetShaderInfoLog(s_id, length, &length, msg));
        //TODO -> it only deal with 2 shader but it also should work with other shader
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader: " << msg << std::endl;
        GLCall(glDeleteShader(s_id));
        delete[] msg;
        return 0;
    }
    return s_id;
}


void Shader::Generate(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GLCall(glAttachShader(id, vs));
    GLCall(glAttachShader(id, fs));
    GLCall(glLinkProgram(id));
    GLCall(glValidateProgram(id));

    //Delete shaders since it's already in the program
    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));
}

void Shader::Bind() const
{
    GLCall(glUseProgram(id));
}

void Shader::UnBind() const
{
    GLCall(glUseProgram(0));
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{

    GLCall(glUniform4f(GetUniformLocation(name), v1, v1, v2, v3));
}

void Shader::SetUniform4fv(const std::string& name, glm::vec4 vector)
{
    GLCall(glUniform4fv(GetUniformLocation(name), 1, &vector[0]));
}

void Shader::SetUniformMat4fv(const std::string name, glm::mat4 matrix)
{
    GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
}


int Shader::GetUniformLocation(const std::string& name)
{
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
        return m_UniformLocationCache[name];
    }
    GLCall(int location = glGetUniformLocation(id, name.c_str()));
    if (location == -1) {
        std::cout << "Warning: uniform '" + name + "' doesn't exists." << std::endl;
    }
    m_UniformLocationCache[name] = location;
    return location;
}
