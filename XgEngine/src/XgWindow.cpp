#include "XgWindow.h"

#include "XgKeyboardEvent.h"

#include <iostream>

using namespace std;

XgKeyboardEvent keyboardEvent;

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) 
{
	keyboardEvent.setMousePosition(xpos, ypos);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	keyboardEvent.setScrollPosition(xoffset, yoffset);
}

XgWindow::XgWindow(int screenWidth, int screenHeight)
{
	cout << "XgWindow Construtor ..." << endl;

	screenSize = new XgScreenSize(screenWidth, screenHeight);
}

XgWindow::~XgWindow()
{
	delete screenSize;
}

/*****************************************************************************
startAnimation()
*****************************************************************************/
int XgWindow::startAnimation()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//#ifdef __APPLE__
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
//#endif

	GLFWmonitor* primary = glfwGetPrimaryMonitor();

	int count;
	GLFWmonitor** monitors = glfwGetMonitors(&count);

	//GLFWvidmode* modes = glfwGetVideoModes(primary, &count);

	// glfw window creation
	// --------------------
	//GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", primary, NULL);
	GLFWwindow* window = glfwCreateWindow(screenSize->width(), screenSize->height(), "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// tell GLFW to capture our mouse
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Initialize GLEW
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return false;
	}

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);
	//glDisable(GL_CULL_FACE);
	//glShadeModel(GL_FLAT);

	initRender(window);

	// TODO Parameterize the 60.0
	static float limitFPS = 1.0f / 60.0f;

	float lastTime = (float) glfwGetTime(), timer = lastTime;
	float deltaTime = 0, nowTime = 0;
	int frames = 0, updates = 0;

	// Render Loop
	// -----------
	while (!glfwWindowShouldClose(window)) {
		// - Measure time
		nowTime = (float) glfwGetTime();
		deltaTime += (nowTime - lastTime) / limitFPS;
		lastTime = nowTime;
	
		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		renderScreen(deltaTime, updates);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();

		frames++;

		// - Reset after one second
		if (glfwGetTime() - timer > 1.0) {
			timer++;
			std::cout << "FPS: " << frames << " Updates:" << updates << std::endl;
			updates = 0, frames = 0;
		}
	}

	closeRender();

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

