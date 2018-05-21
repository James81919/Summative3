#version 450 core

in vec3 fragColor;
in vec2 fragTexCoord;

out vec4 color;

uniform sampler2D tex;
uniform float ambientStr;		// = 0.5f;
uniform vec3 ambientColor;		// = glm::vec3(1.0f, 1.0f, 1.0f);

void main(void)
{
	vec3 ambient = ambientStr * ambientColor;
	color = vec4(ambient, 1.0f) * texture(tex, fragTexCoord);
}