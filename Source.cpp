#include <stdio.h>
#include<GL/glew.h>
#include<GLFW/glfw3.h>


using namespace std;
GLuint VAO, VBO;
float move = 0.0f;
float move2 = 0.0f;

void CreateShape()
{
	//Assign vertices
	GLfloat vertices[] = {
		-0.3f,0.3f,0.0f,
		-0.3f,0.1f,0.0f,
		-0.2f,0.1f,0.0f,
		-0.2f,0.3f,0.0f,
		0.3f,0.3f,0.0f,
		0.3f,0.1f,0.0f,
		0.2f,0.1f,0.0f,
		0.2f,0.3f,0.0f,
		-0.1f,0.1f,0.0f,
		0.3f,0.1f,0.0f,
		-0.1f,0.5f,0.0f,
		0.3f,0.5f,0.0f
	};
	GLfloat facevertices[] = {
		0.0f,0.1f,0.0f,
		0.0f,0.2f,0.0f,
		0.1f,0.1f,0.0f,
		0.2f,0.2f,0.0f,
		0.0f,0.3f,0.0f,
		0.0f,-move+0.4f,0.0f,
		0.1f,0.3f,0.0f,
		0.1f,-move+0.4f,0.0f,
		0.2f,0.3f,0.0f,
		0.2f,-move2 +0.4f,0.0f,
		0.3f,0.3f,0.0f,
		0.3f,-move2 +0.4f,0.0f
	};


	//VAO--> VBO-->DATA-->Pointer to Data
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(facevertices), facevertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
int main()
{
	printf("Welcome to shaders ;) ");

	//init glfw
	if (!glfwInit())
	{
		printf("glfw error");
		glfwTerminate();
		return 1;
	}
	//setup and create window
	GLFWwindow* mainWindow = glfwCreateWindow(800, 600, "Shader1", NULL, NULL);
	if (!mainWindow)
	{
		printf("Window error");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(mainWindow);

	if (glewInit() != GLEW_OK)
	{
		printf("glew error");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}


	//view
	glViewport(0, 0, 800, 600);
	//Opengl Loop 

	CreateShape();
	while (!glfwWindowShouldClose(mainWindow))
	{
		//handlle events
		glfwPollEvents();
		if (move > 0.25f) {
			move = -0.25f;
		}
		else {
			move += 0.002f;
		}
		if (move2 > 0.25f) {
			move2 = -0.25f;
		}
		else {
			move2 += 0.004f;
		}

		//clear bg 
		glClearColor(0.0, 0.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		//draw 
		glBindVertexArray(VAO);
		glColor3f(0.1, 0.1, 0.0);
		glDrawArrays(GL_QUADS, 0, 12);
		glColor3f(0.0, 0.0, 0.0);
		glDrawArrays(GL_QUADS, 0, 12);

		
		glBindVertexArray(0);
		//assign buffers
		glfwSwapBuffers(mainWindow);
	}
	return 0;
}