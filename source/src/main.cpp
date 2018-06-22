#include "glfw_setup.hpp"

#include <GLFW/glfw3.h>
#include <stdio.h>

GLFWwindow* window;

int main(int argc, char const *argv[])
{	
	window = glfw_setup();
		
	while(!glfwWindowShouldClose(window))
	{
		// Clearing screen for next draw
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSwapBuffers(window);    // SWAP BUFFERS
        glfwPollEvents();           // LISTEN FOR WINDOW EVENTS
	}

	glfwDestroyWindow(window);
	return 0;
}