#include "XgWindow.h"

#include "XgKeyboardEvent.h"

#include <iostream>

using namespace std;

XgKeyboardEvent keyboardEvent;

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	cout << "Input: " << key << ":" << scancode << ":" << action << ":" << mods << endl;

	keyboardEvent.setKey(key, scancode, action, mods);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

/*****************************************************************************
mouseCallback()
*****************************************************************************/
void mouseCallback(GLFWwindow* window, double xpos, double ypos) 
{
	keyboardEvent.setMousePosition(xpos, ypos);
}

/*****************************************************************************
scrollCallback()
*****************************************************************************/
void scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
	keyboardEvent.setScrollPosition(xOffset, yOffset);
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

	//GLFWmonitor* primary = glfwGetPrimaryMonitor();
	GLFWmonitor* primary = NULL;

	GLFWwindow* window = glfwCreateWindow(screenSize->width(), screenSize->height(), "LearnOpenGL", primary, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
	glfwSetCursorPosCallback(window, mouseCallback);
	glfwSetScrollCallback(window, scrollCallback);
	glfwSetKeyCallback(window, processInputCallback);

	// tell GLFW to capture our mouse
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Initialize GLEW
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return false;
	}

	// Configure global opengl state
	// -----------------------------
	//glfwSwapInterval(1);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	//glShadeModel(GL_FLAT);

	initRender(window);

	renderLoop(window);

	closeRender();

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

/*void XgWindow::renderLoop(GLFWwindow* window)
{
	float framesPerSecond = 60.0;
	float timePerFrame = 1.0f / framesPerSecond;

	float previous = (float)glfwGetTime();
	float lag = 0.0;
	float timer = (float)glfwGetTime();

	int fps = 0;
	int tickCount = 0;

	while (!glfwWindowShouldClose(window))
	{
		float current = (float)glfwGetTime();
		float elapsed = current - previous;
		float deltaTime = elapsed;
		previous = current;
		lag += elapsed;

		processInput(window);

		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		renderScreen(lag, fps);

		tickCount++;

		if (current - timer > 1.0) {
			timer = current;
			std::cout << "Ticks: " << tickCount << " FPS:" << fps << std::endl;
			fps = 0; tickCount = 0;
		}

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}*/

/*void XgWindow::renderLoop(GLFWwindow* window)
{
	float framesPerSecond = 60.0;
	float timePerFrame = 1.0f / framesPerSecond;

	float lastTimeStamp = (float)glfwGetTime();
	float timer = lastTimeStamp;
	float deltaTime = 0;
	float nowTime = 0;

	int tickCount = 0, fps = 0;

	// Main Render Loop
	// ----------------
	while (!glfwWindowShouldClose(window)) {
		// - Measure time
		nowTime = (float)glfwGetTime();
		deltaTime += (nowTime - lastTimeStamp) / timePerFrame;
		lastTimeStamp = nowTime;

		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		renderScreen(deltaTime, fps);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();

		tickCount++;

		// - Reset after one second
		//if (glfwGetTime() - timer > 1.0) {
		if (nowTime - timer > 1.0) {
			//timer++;
			timer = nowTime;
			std::cout << "Ticks: " << tickCount << " FPS:" << fps << std::endl;
			fps = 0; tickCount = 0;
		}
	}
}*/

void XgWindow::renderLoop(GLFWwindow* window)
{
	// TODO Parameterize the 60.0
	static float limitFPS = 1.0f / 60.0f;

	float lastTime = (float)glfwGetTime(), timer = lastTime;
	float deltaTime = 0, nowTime = 0;
	int tickCount = 0, fps = 0;

	// Main Render Loop
	// ----------------
	while (!glfwWindowShouldClose(window)) {
		// - Measure time
		nowTime = (float)glfwGetTime();
		deltaTime += (nowTime - lastTime) / limitFPS;
		lastTime = nowTime;

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		renderScreen(deltaTime, fps);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();

		tickCount++;

		// - Reset after one second
		if (nowTime - timer > 1.0) {
			timer = nowTime;
			std::cout << "Ticks: " << tickCount << " FPS:" << fps << std::endl;
			fps = 0; tickCount = 0;
		}
	}
}

