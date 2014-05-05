#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>
#include <sstream>

#include <GLFW/glfw3.h>

#include "app.h"
#include "testScene.h"
#include "testScene2.h"

#include "rectangle.h"


app::app()
{
    //ctor
}

app::app(std::string title, int width, int height)
{
    appName = title;
    if (!glfwInit())
    {
        std::cout << "Startup error" << std::endl;
    }

    glfwWindowHint(GLFW_SAMPLES, 16);
    glfwSwapInterval(1);

    window = glfwCreateWindow(width, height, appName.c_str(), NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::cout << "Window creation error" << std::endl;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        std::cout << "GLEW loading error" << std::endl;
    }
}

void app::render()
{
    glfwGetInputMode(window, GLFW_STICKY_KEYS);
    std::string title;

    testScene scene1(window);
    testScene2 scene2(window);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    int whatSceneIsActive = 1;

    while (!glfwWindowShouldClose(window))
    {
        countFPS(&title);

        glfwSetWindowTitle(window, title.c_str());

        if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        {
            whatSceneIsActive = 1;
        }
        if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        {
            whatSceneIsActive = 2;
        }

        whatSceneIsActive == 1? scene1.render() : scene2.render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void app::shutDown()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void app::countFPS(std::string* fpscount)
{
    double currentTime = glfwGetTime();
    framesPerSecond++;
    std::ostringstream sstr;
    if ( currentTime - lastTime >= 1.0 )
    {
        timeCoefficient = 1000/framesPerSecond;
        lastTime += 1.0;
        sstr << framesPerSecond;
        *fpscount = sstr.str();
        framesPerSecond = 0;
    }
}

app::~app()
{
    //dtor
}
