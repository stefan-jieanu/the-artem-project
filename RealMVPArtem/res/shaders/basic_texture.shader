#shader vertex
#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;
layout (location = 2) in float tid;
layout (location = 3) in vec4 color;

uniform mat4 u_Projection;
uniform mat4 u_View = mat4(1.0);

out DATA 
{
    vec4 position;
    vec2 uv;
    float tid;
    vec4 color;
} vs_out;

void main()
{
    vec4 computed_position = vec4(position, 1.0) * u_View * u_Projection;
    gl_Position = computed_position;
    vs_out.position = computed_position;
    vs_out.uv = uv;
    vs_out.tid = tid;
    vs_out.color = color;
}

#shader fragment
#version 330 core

layout (location = 0) out vec4 color;

uniform sampler2D textures[32];

in DATA
{
    vec4 position;
    vec2 uv;
    float tid;
    vec4 color;
} fs_in;

void main()
{

    vec4 texColor = fs_in.color; 
    if (fs_in.tid > 0.0)
    {
        int tid = int(fs_in.tid - 0.5);
        texColor = texture(textures[tid], fs_in.uv);
    }
    color = texColor;
}