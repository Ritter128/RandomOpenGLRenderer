#version 330 core
layout(location = 0) in vec3 aPosition;

uniform mat4 uModelMatrix;
uniform mat4 uViewMatrix;
uniform mat4 uProjMatrix;

mat4 uFinalMatrix;

out vec4 vertColor;

void main()
{
    vertColor = vec4(aPosition, 1.0);
    uFinalMatrix = uProjMatrix * uModelMatrix;
    gl_Position = uFinalMatrix * vec4(aPosition, 1.0);
}
