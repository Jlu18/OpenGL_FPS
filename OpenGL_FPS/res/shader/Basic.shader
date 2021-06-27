#shader vertex

#version 330 core

layout(location = 0) in vec4 a_Pos;

out vec4 vertexColor;
uniform mat4 matrix;

void main() {
    gl_Position = matrix*a_Pos;
}

#shader fragment

#version 330 core
uniform vec4 u_Color;
layout(location = 0) out vec4 color;

void main()
{
    color = u_Color;
}