#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
int main()
{
	GLFWwindow* window;
	// Initialize the library
	if (!glfwInit())
	{
		printf("not working");
		return -1;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(800, 600, "Drawing Window", NULL, NULL);
	float a = 90.0;
	float v = 0.0;
	float x = 0;

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);
	//float incVal = 0.0;
	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		//incVal += 0.1f;
		glClear(GL_COLOR_BUFFER_BIT);

		//Render OpenGL here
		glPushMatrix();
		if (v > 1.0) {
			v = -1.0;
		}
		else {
			v += 0.002;
		}

		a += 5;
		if (a > 180) {
			a = 0;
		}
		for (int i = 0; i <= 100; i++) {
			glPushMatrix();
			glBegin(GL_QUAD_STRIP);
			glColor3f(1.0, 0.0, 0.0);
			glVertex2f(-1.0, -1.0);
			glVertex2f(-1.0, 1.0);
			glVertex2f(1.0, -1.0);
			glVertex2f(1.0, 1.0);
			glEnd();
			glRotatef(a, 0.0, 0.0, 0.0);
			glBegin(GL_QUAD_STRIP);
			if (x <= 100) {
				glColor3f(1.0, 0.0, 0.0);
				x++;
			}
			else if (x < 195) {
				x++;
				glColor3f(0.0, 1.0, 0.0);
			}
			else {
				x = 0;
			}
			glVertex2f(-0.15, -0.25);
			glVertex2f(0.15, -0.25);
			glVertex2f(-0.15, 0.25);
			glVertex2f(0.15, 0.25);
			glEnd();
			glPopMatrix();
			glPushMatrix();
			glRotatef(-2.0 * a, 1.0, 0.0, 0.0);
			//glRotatef(, <#GLfloat x#>, <#GLfloat y#>, <#GLfloat z#>)
			glBegin(GL_QUAD_STRIP);
			if (x <= 100) {
				glColor3f(1.0, 0.0, 0.0);
				x++;
			}
			else if (x < 200) {
				x++;
				glColor3f(0.0, 1.0, 0.0);
			}
			else {
				x = 0;
			}
			glVertex2f(-0.15, -0.25);
			glVertex2f(0.15, -0.25);
			glVertex2f(-0.15, -0.45);
			glVertex2f(0.15, -0.45);
			glEnd();
			glPopMatrix();

			//    prevX = newX;
			//prevY = newY;
		}

		//        glPopMatrix();

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();
}