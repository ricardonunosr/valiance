#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;

out vec3 ourColor;

void main()
{
	gl_Position= vec4(position,1.0);
	ourColor = color;
}

#shader fragment
#version 330 core

out vec4 fragColor;

in vec3 ourColor;

void main()
{
	fragColor = vec4(ourColor,1.0);
}