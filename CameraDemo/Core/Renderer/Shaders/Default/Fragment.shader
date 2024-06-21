#version 430 core

in vec4 i_color;
in vec3 i_normal;
in vec2 i_texCoord;

uniform sampler2D u_textureData;

out vec4 FragmentColor;

void main() {
	FragmentColor = i_color;
}