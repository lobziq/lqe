#include "particleDrawer.h"
#include "shaderLoader.h"
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float offset = 0;

particleDrawer::particleDrawer(GLFWwindow* window): oglObject2d(window)
{
    loadShaderProgram();
}

void particleDrawer::loadShaderProgram()
{
    shaderLoader shaders("shaders/particle2d.vert", "shaders/particle2d.frag", &shaderProgram);
    //uniColor = glGetUniformLocation(shaderProgram, "color");
}

void particleDrawer::fillBufferWithParticles(std::vector <float> particlesArray)
{
    int windowWidth, windowHeight;
    glfwGetWindowSize(activeWindow, &windowWidth, &windowHeight);

    float x, y, z;
    for (int i=0; i < particlesArray.size(); i+=2)
    {
        vertices.push_back((GLfloat)particlesArray[i]*2/windowWidth);
        vertices.push_back((GLfloat)particlesArray[i+1]*2/windowHeight*-1);
    }
    for (int j; j < particlesArray.size(); j+=2)
    {
        //debug выводим что назаполн€ли в координатах экрана
        //std::cout << particlesArray[j] << " " << particlesArray[j+1] << std::endl;
    }
}


void particleDrawer::draw()
{
    glUseProgram(shaderProgram);

    if (glfwGetKey(activeWindow, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        for (int i = 0; i < vertices.size(); i+=2)
        {
            vertices[i] += 0.001;
        }
        offset += 0.001;
        std::cout << offset << std::endl;
    }
    if (glfwGetKey(activeWindow, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        for (int i = 0; i < vertices.size()/2; i+=2)
        {
            vertices[i] -= 0.001;
        }
        offset -= 0.001;
        std::cout << offset << std::endl;
    }

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat), &vertices[0], GL_DYNAMIC_DRAW);

    posAttribute = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttribute);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(posAttribute, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glPointSize(4);
    glDrawArrays(GL_POINTS, 0, vertices.size()/2);

    glDisableVertexAttribArray(posAttribute);
}


particleDrawer::~particleDrawer()
{
    //dtor
}
