#version 330 core

in vec2 texCoord;

out vec4 fragmentColor;

uniform sampler2D texture0;
uniform sampler2D texture1;
uniform float blend;

void main(){
    vec2 texCoordFlipped = vec2(texCoord.x, 1 - texCoord.y);
	fragmentColor = mix(texture(texture0, texCoordFlipped), texture(texture1, texCoordFlipped), blend);
}