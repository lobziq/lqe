#include "oglObject2d.h"
#include "shaderLoader.h"

oglObject2d::oglObject2d(GLFWwindow *window): oglObject(window)
{
    //loadShaderProgram();
}

void oglObject2d::loadShaderProgram()
{
    shaderLoader shaders("shaders/object2d.vert", "shaders/object2d.frag", &shaderProgram);

    uniTexture = glGetUniformLocation(shaderProgram, "tex");
    uniColor = glGetUniformLocation(shaderProgram, "color");
}
