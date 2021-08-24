#shader vertex

#version 330 core

layout(location = 0) in vec4 a_Pos;
layout(location = 1) in vec2 a_TexCoord;

uniform mat4 u_Matrix;

out vec2 texCoord;

void main() {
    gl_Position = u_Matrix * a_Pos;
    texCoord = a_TexCoord;
}

#shader fragment

#version 330 core

layout(location = 0) out vec4 color;

in vec2 texCoord;

uniform sampler2D u_Sprite;

void main()
{
    color = texture(u_Sprite,texCoord);
}