#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 aNormal;

out vec3 Normal;
out vec3 FragPos;

uniform mat4 u_MVP;
uniform mat4 u_model;

void main()
{
	gl_Position= u_MVP * vec4(position,1.0);
    FragPos = vec3(u_model * vec4(position, 1.0));
    Normal = mat3(transpose(inverse(u_model))) * aNormal;
}

#shader fragment
#version 330 core

in vec3 Normal;
in vec3 FragPos;

out vec4 fragColor;

uniform vec3 u_LightColor;
uniform vec3 u_ObjectColor;
uniform vec3 u_LightPos;
uniform vec3 u_ViewPos;

void main()
{
    //Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(u_LightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * u_LightColor;

    //Ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * u_LightColor;

    //Specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(u_ViewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm); 
    //32 represents shininess
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * u_LightColor;  

    vec3 result = (diffuse+ambient+specular) * u_ObjectColor;
	fragColor = vec4(result,1.0);
}