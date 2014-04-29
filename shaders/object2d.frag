#version 150

in vec2 UV;

uniform vec4 color;
uniform sampler2D tex;

out vec4 outColor;

void main()
{
    //outColor = vec4(1, 1, 1, texture2D(tex, UV).a) * color;

    outColor = texture2D(tex, UV) * (color.rgb, 1.0);
    //outColor = vec4(color.rgb, texture2D(tex, UV).a);
}
