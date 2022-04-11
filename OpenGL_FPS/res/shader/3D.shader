#shader vertex

#version 330 core

layout(location = 0) in vec3 a_Pos;
layout(location = 1) in vec3 a_Normal;
//layout(location = 2) in vec2 a_TexCoord;

uniform mat4 u_ViewProjMatrix;
uniform mat4 u_Matrix;

out vec3 fragPos;
out vec3 normal;

void main() {
    fragPos = vec3(u_Matrix * vec4(a_Pos, 1.0));
    //inverse operation is costly
    normal  = mat3(transpose(inverse(u_Matrix))) * a_Normal;
    
    gl_Position = u_ViewProjMatrix * u_Matrix * vec4(a_Pos,1.0);
}

#shader fragment

#version 330 core

in vec3 fragPos;
in vec3 normal;

uniform vec4 u_Color;
//base light
uniform vec3 u_LightPos;
uniform vec4 u_LightColor;

layout(location = 0) out vec4 color;

void main()
{
    //ambient light
    float ambient_intensity = 0.1;
    vec4 ambient = u_LightColor * ambient_intensity;

    //diffuse
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(u_LightPos - fragPos);
    //if dot product is less than 0, it means the angle between normal and direction of the light is greater than 90 degree
    //which means there's no light shining on its surface
    float diff = max(dot(norm, lightDir), 0.0);
    vec4 diffuse = diff * u_LightColor;

    //specular
    //phong(calculated)
    color = (ambient + diffuse) * u_Color;
}