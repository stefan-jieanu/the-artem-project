//#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

uniform mat4 u_ProjectionView;
uniform mat4 u_Transform;

out vec2 v_texCoord;

void main()
{
	v_texCoord = texCoord;
	gl_Position = u_ProjectionView * u_Transform * vec4(position, 1.0);
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_texCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	color = texture(u_Texture, v_texCoord) * u_Color;
}