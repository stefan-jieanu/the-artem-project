#version 330 core

layout(location = 0) in vec3 _position;
layout(location = 1) in vec4 _color;

uniform mat4 u_ProjectionView;

out vec4 v_Color;

void main()
{
	gl_Position = u_ProjectionView * vec4(_position, 1.0);
	v_Color = _color;
}