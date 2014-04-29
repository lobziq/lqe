#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "oglObject3d.h"
#include "shaderLoader.h"
#include "camera.h"

oglObject3d::oglObject3d(GLFWwindow *window, camera *sceneCamera): oglObject(window)
{
    objectCam = sceneCamera;
    //loadShaderProgram();
}

void oglObject3d::loadShaderProgram()
{
    shaderLoader shaders("shaders/object3d.vert", "shaders/object3d.frag", &shaderProgram);

    uniTexture = glGetUniformLocation(shaderProgram, "tex");
    uniColor = glGetUniformLocation(shaderProgram, "color");
    uniMVP = glGetUniformLocation(shaderProgram, "MVP");

}

void oglObject3d::useCamera()
{
    projectionMatrix = objectCam->getProjectionMatrix();
    viewMatrix = objectCam->getViewMatrix();

    mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;

    glUniformMatrix4fv(uniMVP, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
}

void oglObject3d::setPosition(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    modelMatrix = glm::mat4(1.0);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z));
}

void oglObject3d::setPosition(glm::vec3 position)
{
    x = position.x;
    y = position.y;
    z = position.z;
    modelMatrix = glm::mat4(1.0);
    modelMatrix = glm::translate(modelMatrix, position);
}

glm::vec3 oglObject3d::getPosition()
{
    return glm::vec3(x, y, z);
}

void oglObject3d::draw()
{
    useTextures();
    setColor(r, g, b);
    useCamera();
    useAttributes(3);
}
