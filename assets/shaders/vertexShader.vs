#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 vertexColor;
out vec2 texCoord;

uniform float xOffset;

void main(){
	gl_Position = vec4(aPos.x + xOffset, aPos.y, aPos.z, 1.0f);
    vertexColor = aColor;
    texCoord = aTexCoord;
};