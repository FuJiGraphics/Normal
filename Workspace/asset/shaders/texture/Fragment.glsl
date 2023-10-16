#version 330 core

in vec2 TexCoord;

uniform sampler2D u_Texture;

out vec4 FragColor;

void main()
{
	FragColor = texture( u_Texture, TexCoord * vec2( 1.0f, -1.0f ) );
}
