#shader vertex

#version 330 core

layout(location = 0) in vec4 position;

out vec4 vertexColor;
uniform mat4 matrix;

void main() {
    gl_Position = matrix*position;
}

#shader fragment

#version 330 core
layout(location = 0) out vec4 color;

void main()
{
    color = vec4( 1.0, 1.0, 1.0, 1.0 );
}