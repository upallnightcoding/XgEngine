#version 330 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec3 aColor;

uniform mat4 u_Transform;
uniform mat4 u_View;
uniform mat4 u_Projection; 

out vec3 Normal;
out vec2 TexCoord;
out vec3 FragPos;

void main()
{
   gl_Position = u_Projection * u_View * u_Transform * vec4(aPosition, 1.0);
   
   //Normal = aNormal;
   Normal = vec3(u_Transform * vec4(aNormal, 1.0));
   TexCoord = aTexCoord;
   FragPos = vec3(u_Transform * vec4(aPosition, 1.0));
}
@
#version 330 core

uniform vec4 u_Color;
uniform vec3 u_ViewPosition;
uniform sampler2D u_Texture;

uniform vec3 u_LightPosition;
uniform vec3 u_LightColor;

in vec3 Normal;
in vec2 TexCoord;
in vec3 FragPos;

out vec4 FragColor;

void main()
{
	vec3 norm = normalize(Normal);
	
	// Ambient Light Calculations
	//---------------------------
	float ambientStrength = 0.5;
	vec3 ambientColor = vec3(1.0);
	vec3 ambientLight = ambientStrength * ambientColor;

	// Diffuse Light Calculations
	//---------------------------
	float diffuseStrength = 1.0;	
	vec3 lightDir = normalize(u_LightPosition - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuseLight = diffuseStrength * diff * u_LightColor;
	
	// Specular Light Calculations
	//----------------------------
	float specularStrength = 1.0;
	vec3 viewDir = normalize(u_ViewPosition - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);  
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 30.0);
	vec3 specularLight = specularStrength * spec * u_LightColor;
	
	// Fragment Point Color
	//---------------------
	FragColor = 
		vec4(ambientLight + diffuseLight + specularLight, 1.0) * 
		texture(u_Texture, TexCoord);
}