#shader vertex

#version 330 core

layout(location = 0) in vec3 a_Pos;
layout(location = 1) in vec3 a_Normal;
//layout(location = 2) in vec2 a_TexCoord;

uniform mat4 u_ViewProjMatrix;
uniform mat4 u_Matrix;

void main() {
    gl_Position = u_ViewProjMatrix * u_Matrix * vec4(a_Pos,1.0);
}

#shader fragment

#version 330 core

uniform vec4 u_Color;

layout(location = 0) out vec4 color;

void main()
{
    color = u_Color;
}