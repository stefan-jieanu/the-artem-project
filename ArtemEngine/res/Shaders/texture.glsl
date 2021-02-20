#shader vertex
#version 330 core

layout(location = 0) in vec3 _position;
layout(location = 1) in vec4 _color;
layout(location = 2) in vec2 _texCoord;

uniform mat4 u_ProjectionView;

out vec4 v_Color;
out vec2 v_texCoord;

void main()
{
	v_Color = _color;
	v_texCoord = _texCoord;
	gl_Position = u_ProjectionView * vec4(_position, 1.0);
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 v_Color;
in vec2 v_texCoord;

uniform sampler2D u_Texture;

void main()
{
	//color = texture(u_Texture, v_texCoord) * u_Color;
	color = v_Color;
}