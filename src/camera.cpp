#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

#include "camera.h"

float wheel;

camera::camera()
{

    //ctor
}

void scroll(GLFWwindow* window, double x, double y)
{
    wheel = (float)y;
    //std::cout << wheel << std::endl;
}


void camera::computeMatricesFromInputs(GLFWwindow *window)
{
        static double lastTime = glfwGetTime();

        double currentTime = glfwGetTime();
        float deltaTime = float(currentTime - lastTime);

        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        int ww,wh;
        glfwGetWindowSize(window, &ww, &wh);

        glfwSetCursorPos(window, ww/2, wh/2);

        horizontalAngle += mouseSpeed * float(ww/2 - xpos );
        verticalAngle   += mouseSpeed * float(wh/2 - ypos );

        glm::vec3 direction(
                cos(verticalAngle) * sin(horizontalAngle),
                sin(verticalAngle),
                cos(verticalAngle) * cos(horizontalAngle)
        );

        glm::vec3 right = glm::vec3(
                sin(horizontalAngle - 3.14f/2.0f),
                0,
                cos(horizontalAngle - 3.14f/2.0f)
        );

        glm::vec3 up = glm::cross( right, direction );

        if (glfwGetKey( window, GLFW_KEY_W ) == GLFW_PRESS){
                position += direction * deltaTime * speed;
        }
        if (glfwGetKey( window, GLFW_KEY_S ) == GLFW_PRESS){
                position -= direction * deltaTime * speed;
        }
        if (glfwGetKey( window, GLFW_KEY_D ) == GLFW_PRESS){
                position += right * deltaTime * speed;
        }
        if (glfwGetKey( window, GLFW_KEY_A ) == GLFW_PRESS){
                position -= right * deltaTime * speed;
        }

        float FoV = initialFoV;

        ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);

        glm::vec3(0.0, 0.0, 0.0);

        ViewMatrix       = glm::lookAt(
                                                                position,
                                                                position+direction,
                                                                up
                                                   );

        lastTime = currentTime;
}

void camera::strategyCamera(GLFWwindow* window)
{
    glfwSetScrollCallback(window, scroll);

    static double lastTime = glfwGetTime();

    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);

    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    int ww, wh;
    glfwGetWindowSize(window, &ww, &wh);

    if (xpos < ww*0.02)
    {
        position.x -= deltaTime * speed;
        watchPos.x -= deltaTime * speed;

    }
    if (xpos > ww*0.98)
    {
        position.x += deltaTime * speed;
        watchPos.x += deltaTime * speed;
    }
    if (ypos < wh*0.02)
    {
        position.z -= deltaTime * speed;
        watchPos.z -= deltaTime * speed;
    }
    if (ypos > wh*0.98)
    {
        position.z += deltaTime * speed;
        watchPos.z += deltaTime * speed;
    }
    position.y += deltaTime * speed * 20 * wheel;

    float FoV = initialFoV;

    ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);

    ViewMatrix       = glm::lookAt(
                                   position,
                                   watchPos,
                                   glm::vec3(0, 1, 0)
                                   );

    lastTime = currentTime;
    wheel = 0;
}


glm::mat4 camera::getProjectionMatrix()
{
    return ProjectionMatrix;
}

glm::mat4 camera::getViewMatrix()
{
    return ViewMatrix;
}


camera::~camera()
{
    //dtor
}
