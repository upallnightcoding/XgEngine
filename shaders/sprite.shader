#version 330 core

// VAO Layout Locations
//---------------------
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

// Object Uniform Variables
//-------------------------
uniform mat4 u_Transform;
uniform mat4 u_View;
uniform mat4 u_Projection;

// Out Bound Variables
//--------------------
out vec3 ourColor;
out vec2 TexCoord;

void main()
{
    gl_Position = vec4(aPosition, 1.0);
	gl_Position = u_Projection * u_View * u_Transform * vec4(aPosition, 1.0);
	
    ourColor = aColor;
    TexCoord = aTexCoord;
}
@
#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    //FragColor = texture(ourTexture, TexCoord);
	
	vec4 texColor = texture(ourTexture, TexCoord);
	
    if(texColor.a < 1.0) {
        discard;
	}
		
    FragColor = texColor;
}
