#version 430 core

layout (location = 0) in vec3 _position;
layout (location = 1) in vec3 _normal;
layout (location = 2) in vec2 _texCoord;

uniform vec4 _color;
uniform mat4 _transform;

out vec4 i_color;
out vec3 i_normal;
out vec2 i_texCoord;

void main() {
	gl_Position = _transform * vec4(_position, 1.f);
	i_color = _color;
	i_normal = _normal;
	i_texCoord = _texCoord;
}