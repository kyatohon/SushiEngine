#version 430

in vec4 myColor;
in vec2 texCoord;
out vec4 fColor;

uniform sampler2D texture;

void main()
{
	 // fColor = texture2D(texture, texCoord);
	 fColor = vec4(1,0,0,1);
};