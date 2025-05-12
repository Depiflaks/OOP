//
// Created by smmm on 06.05.2025.
//

#include "shape/shapeReader/ShapeReader.h"
#include "shape/solidShape/triangle/Triangle.h"
#include <GLFW/glfw3.h>
#include <canvas/openGL/GlCanvas.h>
#include <iostream>

void PrintShape(const std::shared_ptr<Shape>& shape)
{
	if (shape == nullptr)
		std::cout << "No shapes available.\n";
	else
		shape->Print(std::cout);
}

int main()
{
	const auto shapes = ShapeReader::ReadShapes(std::cin);

	if (!glfwInit())
	{
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Picture", nullptr, nullptr);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	GlCanvas canvas;

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		for (const auto& shape : shapes)
		{
			shape->Draw(canvas);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
