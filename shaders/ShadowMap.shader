#version 330 core

layout (location = 0) in vec3 aPosition;

uniform mat4 u_LightSpaceMatrix;
uniform mat4 u_Transform;

void main()
{
    gl_Position = u_LightSpaceMatrix * u_Transform * vec4(aPosition, 1.0);
}
@
#version 330 core

//layout (location = 0) out float fragmentDepth;

void main()
{             
    //fragmentDepth = gl_FragCoord.z;
}  