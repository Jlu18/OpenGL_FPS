#shader vertex

#version 330 core

layout(location = 0) in vec4 a_Pos;

uniform mat4 u_Matrix;

void main() {
    gl_Position = u_Matrix*a_Pos;
}

#shader fragment

#version 330 core

uniform vec4 u_Color;

layout(location = 0) out vec4 color;

void main()
{
    color = u_Color;
}