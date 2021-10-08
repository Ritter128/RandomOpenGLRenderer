#version 330 core
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec2 aTexCoords;

uniform mat4 uModelMatrix;
uniform mat4 uProjMatrix;

mat4 uFinalMatrix;

out vec4 vertColor;
out vec2 texCoords;

void main()
{
    texCoords = aTexCoords;
    vertColor = vec4(aPosition, 1.0);
    uFinalMatrix = uProjMatrix * uModelMatrix;
    gl_Position = uFinalMatrix * vec4(aPosition, 1.0);
}
