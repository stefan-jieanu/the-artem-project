#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

uniform mat4 u_ProjectionView;

out DATA
{
	vec4 pos;
	vec4 color;
} vs_out;

void main()
{
	vs_out.pos = u_ProjectionView * vec4(position, 1.0);;
	vs_out.color = color;
	gl_Position = vs_out.pos;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in DATA
{
	vec3 pos;
	vec4 color;
} fs_in;

void main()
{
	color = fs_in.color;
}