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
   Normal = aNormal;
   //Normal = vec3(u_Transform * vec4(aNormal, 1.0));
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
   //FragColor = vec4(oColor, 1.0) + u_Color;
   //FragColor = texture(u_Texture, TexCoord);
   //FragColor = texture(u_Texture, TexCoord) + vec4(oColor, 1.0) + u_Color;
   
	//vec3 lightPos = vec3(0.0, 0.0, 0.0);
	//vec3 lightColor = vec3(1.0);
	
	float ambientStrength = 0.1;
	float diffuseStrength = 1.0;
	
	vec3 ambientColor = vec3(1.0);
	vec3 ambientLight = ambientStrength * ambientColor;
   
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(u_LightPosition - FragPos);
	
	float diff = max(dot(Normal, lightDir), 0.0);
	vec3 diffuse = u_LightColor * diff;
	
	float specularStrength = 1.0;
	vec3 viewDir = normalize(u_ViewPosition - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);  
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 100);
	vec3 specular = specularStrength * spec * u_LightColor;
	
	//diffuse = vec3(0.0);
   
	FragColor = 
		vec4(ambientLight + diffuse, 1.0) * 
		texture(u_Texture, TexCoord);
		
	//FragColor = 
		//vec4(ambientLight + diffuse + specular, 1.0) * 
		//texture(u_Texture, TexCoord);

}