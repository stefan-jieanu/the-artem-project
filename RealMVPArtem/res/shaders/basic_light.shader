#shader vertex
#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

uniform mat4 u_Projection = mat4(1.0);
uniform mat4 u_View = mat4(1.0);
uniform mat4 u_Model = mat4(1.0);

out DATA 
{
    vec4 position;
    vec4 color;
} vs_out;

void main()
{
    vec4 computed_position = vec4(position, 1.0) * u_Model * u_View * u_Projection;
    gl_Position = computed_position;
    vs_out.position = computed_position;
    vs_out.color = color;
}

#shader fragment
#version 330 core

layout (location = 0) out vec4 color;

uniform vec2 light_pos;

in DATA
{
    vec4 position;
    vec4 color;
} fs_in;

void main()
{
    float intensity = 1.0 / length(fs_in.position.xy - light_pos) * 0.1;
    color = fs_in.color * intensity;
    // color = fs_in.color;
}