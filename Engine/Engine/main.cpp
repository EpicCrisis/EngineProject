
#include <GLFW\glfw3.h>
#include <iostream>

using namespace std;

void Update(float _deltaTime, float _FPS)
{
    system("CLS");
    cout << "Delta Time : " << _deltaTime << endl;
    cout << "FPS : " << _FPS << endl;
}

int main(void)
{
    GLFWwindow* window;

    float lastUpdateTime = (float)glfwGetTime();

    // Initialize the library.
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context.
    window = glfwCreateWindow(640, 480, "VozEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current.
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    // Loop until the user closes the window.
    while (!glfwWindowShouldClose(window))
    {
        // Render here,
        glClear(GL_COLOR_BUFFER_BIT);

        glfwGetTime();

        // Calculate delta time and FPS.
        float deltaTime = glfwGetTime() - lastUpdateTime;
        lastUpdateTime = (float)glfwGetTime();
        float FPS = 1.0f / deltaTime;

        // Swap front and back buffers.
        glfwSwapBuffers(window);

        Update(deltaTime, FPS);

        // Poll for and process events.
        glfwPollEvents();
    }

    return 0;
}