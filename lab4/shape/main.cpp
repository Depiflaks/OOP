//
// Created by smmm on 06.05.2025.
//

#include "shape/shapeReader/ShapeReader.h"
#include "shape/solidShape/triangle/Triangle.h"

#include <GLFW/glfw3.h>
#include <canvas/openGL/GlCanvas.h>
#include <functional>
#include <iostream>

void PrintShape(const std::shared_ptr<Shape>& shape)
{
	if (shape == nullptr)
		std::cout << "No shapes available.\n";
	else
		shape->Print(std::cout);
}

constexpr int k_windowWidth = 800;
constexpr int k_windowHeight = 600;

void InitOpenGl()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
}

void StartDrawingLoop(GLFWwindow* window, const std::function<void()>& Draw)
{
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void StopDrawing(GLFWwindow* window)
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

int main()
{
	const auto shapes = ShapeReader::ReadShapes(std::cin);

	if (!glfwInit())
		return -1;

	InitOpenGl();

	GLFWwindow* window = glfwCreateWindow(k_windowWidth, k_windowHeight, "Picture", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	GlCanvas canvas;

	const std::function DrawShapes{ [&shapes, &canvas] {
		for (const auto& shape : shapes)
			shape->Draw(canvas);
	}};

	StartDrawingLoop(window, DrawShapes);

	StopDrawing(window);
	return 0;
}
