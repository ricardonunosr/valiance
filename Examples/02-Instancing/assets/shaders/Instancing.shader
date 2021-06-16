#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
//layout(location = 1) in vec3 color;
layout(location = 1) in vec2 textCoord;

//out vec3 ourColor;
out vec2 ourTextureCoord;

uniform mat4 u_MVP;

void main()
{
    gl_Position = u_MVP * vec4(position, 1.0);
    //ourColor = color;
    ourTextureCoord = textCoord;
}

#shader fragment
#version 330 core

out vec4 fragColor;

//in vec3 ourColor;
in vec2 ourTextureCoord;

uniform sampler2D ourTexture;

void main()
{
    fragColor = texture(ourTexture, ourTextureCoord);
    // fragColor = vec4(ourColor, 1.0);
}