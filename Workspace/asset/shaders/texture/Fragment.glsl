#version 330 core

in vec2 TexCoord;

uniform vec4 u_SquareColor;
uniform sampler2D u_Texture;

out vec4 FragColor;

void main()
{
	FragColor = u_SquareColor * texture( u_Texture, TexCoord );
}
