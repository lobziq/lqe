#version 150


in vec2 UV;
uniform sampler2D tex;
//uniform vec4 color;
out vec4 outColor;

void main()
{
    outColor = texture(tex, UV);
}
