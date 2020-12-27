#shader vertex
#version 330 core

layout (location = 0) in vec3 position;

uniform mat4 u_Projection = mat4(1.0);
uniform mat4 u_View = mat4(1.0);
uniform mat4 u_Model = mat4(1.0);

void main()
{
    gl_Position = vec4(position, 1.0) * u_Model * u_View * u_Projection;
}

#shader fragment
#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 u_Color;

void main()
{
    color = u_Color;
}