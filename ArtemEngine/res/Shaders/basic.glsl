#shader vertex
#version 330 core

layout(location = 0) in vec3 position;

uniform mat4 u_ProjectionView;
uniform mat4 u_Transform;

out DATA
{
	vec4 pos;
} vs_out;

void main()
{
	vs_out.pos = u_ProjectionView * u_Transform * vec4(position, 1.0);;
	gl_Position = vs_out.pos;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;

in DATA
{
	vec3 pos;
} fs_in;

void main()
{
	color = u_Color;
}