#include "XgShader.h"

#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>

#include "Xg.h"
#include "XgConstant.h"
#include "XgKeyboardEvent.h"

// External Declarations
//----------------------
extern XgKeyboardEvent keyboardEvent;

XgShader::XgShader(string pathName)
{
	this->pathName = pathName;
}

XgShader::~XgShader()
{
}

/*****************************************************************************
setProjection() -
*****************************************************************************/
void XgShader::setProjection(float fov, int screenWidth, int screenHeight, float near, float far)
{
	mat4 u_projection = perspective(radians(fov), (float)screenWidth / (float)screenHeight, near, far);

	int projectionLocation = glGetUniformLocation(shaderProgram, XgConstant::U_PROJECT);
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, value_ptr(u_projection));
}


/*****************************************************************************
use() -
*****************************************************************************/
void XgShader::use(XgCamera &camera, XgLight &light, XgTransform &transform)
{
	glUseProgram(shaderProgram);

	int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
	//int viewPosLocation = glGetUniformLocation(shaderProgram, "viewPos");

	//shader->setProjection(45.0f, screenWidth, screenHeight, 0.1f, 100.0f);
	setProjection(keyboardEvent.getFov(), 800, 600, 0.1f, 100.0f);

	//vec3 viewPos = camera.getViewPosition();
	//glUniform3f(viewPosLocation, viewPos.x, viewPos.y, viewPos.z);

	// Define Light Telemetry
	//-----------------------
	uniform(XgConstant::U_LIGHT_COLOR, light.getColour());
	uniform(XgConstant::U_LIGHT_POSITION, light.getPosition());

	// Define Camera Telemetry
	//------------------------
	uniform("viewPos", camera.getPosition());

	uniform(XgConstant::U_VIEW, camera.getView());

	vec4 colour = transform.getColour();
	glUniform4f(vertexColorLocation, colour.r, colour.g, colour.b, colour.a);

	uniform("u_transform", transform.getTransformMatrix());
}

/*****************************************************************************
uniform() -
*****************************************************************************/
void XgShader::uniform(string name, vec3 value)
{
	int location = glGetUniformLocation(shaderProgram, name.c_str());
	glUniform3f(location, value.x, value.y, value.z);
}

/*****************************************************************************
uniform() -
*****************************************************************************/
void XgShader::uniform(string name, mat4 value)
{
	int location = glGetUniformLocation(shaderProgram, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(value));
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgShader::create()
{
	string path = XgConstant::WORK_SPACE + XgConstant::SHADER_DIRECTORY;
	string filename = pathName;
	string source = readShaderFile(path + filename);
	size_t seperator = source.find("@");
	string vertexSource = source.substr(0, seperator);
	string fragmentSource = source.substr(seperator + 1, source.length());

	cout << "VertexSoure: \n" << vertexSource << endl;
	cout << "FragmentSource: \n" << fragmentSource << endl;

	const char *vertexShaderSource = vertexSource.c_str();
	const char *fragmentShaderSource = fragmentSource.c_str();

	int vertexShader = compile(vertexShaderSource, GL_VERTEX_SHADER);
	int fragmentShader = compile(fragmentShaderSource, GL_FRAGMENT_SHADER);

	link(vertexShader, fragmentShader);
}

/*****************************************************************************
link() -
*****************************************************************************/
void XgShader::link(int vertexShader, int fragmentShader)
{
	// link shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int success;
	char infoLog[512];

	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

/*****************************************************************************
compile() - Compiles the source shader and defines a shader id that is 
returned to the caller.  If there is an error in the compilation a message is
written to standard output.  Upon an error the shader id is also set to -1.
*****************************************************************************/
int XgShader::compile(const char *source, GLenum shaderType)
{
	// Create the shader id and attempt to compile the source
	//-------------------------------------------------------
	int shaderId = glCreateShader(shaderType);
	glShaderSource(shaderId, 1, &source, NULL);
	glCompileShader(shaderId);

	// Write to standard output any shader compilation errors
	//-------------------------------------------------------
	int success;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		shaderId = -1;
	}

	return(shaderId);
}

/*****************************************************************************
readShaderFile() - Reads the entire content of the shader file.  The content
is read in as a "ostringstream" and then converted to a string.  Any exception
is not handled and returns back to the caller.
*****************************************************************************/
string XgShader::readShaderFile(const string pathname)
{
	string source = "";

	ifstream in(pathname, std::ios::in | std::ios::binary);

	if (in) {
		ostringstream contents;
		contents << in.rdbuf();
		in.close();
		source = contents.str();
	}
	
	return(source);
}
