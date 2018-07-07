
#include <GLFW\glfw3.h>
#include <Windows.h>
#include <gl/GLU.h>
#include <iostream>
#include "Application.h"

const int RESOLUTION_X = 640;
const int RESOLUTION_Y = 480;

bool bVSync = true;

float lastUpdateTime = 0.0f;
float deltaTime = 0.0f;
float FPS = 0.0f;

using namespace std;

void OnWindowResized(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Use ortho 2D view.
    gluOrtho2D(0, width, 0, height);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(void)
{
    GLFWwindow* window;
    Application app;

    lastUpdateTime = (float)glfwGetTime();

    // Initialize the library.
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context.
    window = glfwCreateWindow(RESOLUTION_X, RESOLUTION_Y, "VozEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(window, OnWindowResized);

    // Make the window's context current.
    glfwMakeContextCurrent(window);
    glfwSwapInterval(bVSync ? 1 : 0);

    OnWindowResized(window, RESOLUTION_X, RESOLUTION_Y);

    app.Start();

    // Loop until the user closes the window.
    while (!glfwWindowShouldClose(window))
    {
        app.Update(deltaTime);
        app.Draw();

        // Render here,
        glClear(GL_COLOR_BUFFER_BIT);

        //glfwGetTime();

        // Calculate delta time and FPS.
        deltaTime = (float)glfwGetTime() - lastUpdateTime;
        lastUpdateTime = (float)glfwGetTime();
        FPS = 1.0f / deltaTime;

        // Swap front and back buffers.
        glfwSwapBuffers(window);

        // Poll for and process events.
        glfwPollEvents();
    }

    return 0;
}