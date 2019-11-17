#version 330 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 u_transform;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec3 Normal;
out vec2 TexCoord;
out vec3 FragPos;

void main()
{
   gl_Position = u_projection * u_view * u_transform * vec4(aPosition, 1.0);
   Normal = aNormal;
   //Normal = vec3(u_transform * vec4(aNormal, 1.0));
   TexCoord = aTexCoord;
   FragPos = vec3(u_transform * vec4(aPosition, 1.0));
}
@
#version 330 core

uniform vec4 ourColor;
uniform vec3 viewPos;
uniform sampler2D ourTexture;

uniform vec3 u_LightPosition;
uniform vec3 u_LightColor;

in vec3 Normal;
in vec2 TexCoord;
in vec3 FragPos;

out vec4 FragColor;

void main()
{
	float ambientStrength = 0.1;
	vec3 ambientColor = vec3(1.0);
	vec3 ambientLight = ambientStrength * ambientColor;
   
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(u_LightPosition - FragPos);
	
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = u_LightColor * diff;
	
	FragColor = vec4(ambientLight, 1.0);
		
}