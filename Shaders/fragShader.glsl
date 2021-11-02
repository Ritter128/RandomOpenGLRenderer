#version 330 core

in vec4 vertColor;
in vec2 texCoords;

out vec4 FragColor;

uniform sampler2D uTexSample;

vec4 CalculateAverage(in vec4 vec)
{
    float total = vec.r + vec.g + vec.b + vec.a;
    float avg = total/4;
    vec4 newVec = vec4(avg);
    return newVec;
}

void main()
{
    FragColor = texture2D(uTexSample, texCoords); 
}
