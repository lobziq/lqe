#version 150

in vec3 position;
in vec2 uvPosition;

uniform mat4 MVP;

out vec2 UV;

void main()
{
    UV = uvPosition;
    gl_Position = MVP * vec4(position, 1.0);
}
