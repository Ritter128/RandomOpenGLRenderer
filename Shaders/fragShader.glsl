#version 330 core

in vec4 vertColor;
in vec2 texCoords;

out vec4 FragColor;

uniform sampler2D uTexSample;

void main()
{
    FragColor = texture2D(uTexSample, texCoords);
}