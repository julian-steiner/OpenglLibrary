#version 330 core
out vec4 FragColor;
in vec2 textureCoord;
uniform sampler2D texture_s;
void main()
{
    FragColor = texture(texture_s, textureCoord);
}