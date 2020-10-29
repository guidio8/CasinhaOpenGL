#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


void DesenhaPrimitivas(int primitiva) {
    switch (primitiva) {
    case 1:
        glPointSize(10);
        glBegin(GL_POINTS);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();
        break;
    case 2:
        glBegin(GL_LINES);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2f(0.0f, 0.0f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(0.75f, 0.75f);
        glEnd();
        break;
    case 3:
        int CirclePoints = 5    ;
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < CirclePoints; i++) {
            float angle = 2 * 3.14159 * i / CirclePoints;
            glVertex2f((0.15 * cos(angle)) - 0.5, (0.15 * sin(angle)) + 0.20);
        }
        glEnd();
        break;
    }
}

void DesenhaCasinha() {
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -1.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
    GLint CirclePoints = 1000;
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < CirclePoints; i++) {
        float angle = 2 * 3.14159 * i / CirclePoints;
        glVertex2f((0.15 * cos(angle)) - 0.5, (0.15 * sin(angle)) + 0.20);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.75f, -1.0f);
    glVertex2f(-0.25f, -1.0f);
    glVertex2f(-0.25f, -0.25f);
    glVertex2f(-0.75f, -0.25f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.25f, -0.1f);
    glVertex2f(0.25f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, -0.1f);
    glEnd();
}

void teclado(unsigned char key, int x, int y) {
    if (key == 27) {
        exit(0);
    }
}

int main(void)
{
    int primitiva;
    std::cin >> primitiva;
    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        if (primitiva == 0) {
            DesenhaCasinha();
        }else {
            DesenhaPrimitivas(primitiva);
        }

        glFlush();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            exit(0);
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}