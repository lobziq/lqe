#version 150

in vec2 position;
in vec2 uvPosition;

out vec2 UV;

void main()
{
    UV = uvPosition;
    gl_Position = vec4(position.x-1.0f, position.y+1.0f, 0.0f, 1.0f);
}
