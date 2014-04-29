#include "rectangle.h"

rectangle::rectangle(int x, int y, int width, int height, GLFWwindow* window): oglObject2d(window)
{
    loadShaderProgram();
    uniTexture = glGetUniformLocation(shaderProgram, "tex");
    uniColor = glGetUniformLocation(shaderProgram, "color");

    setRectangle(x, y, width, height);
    setColor(1.0f, 1.0f, 1.0f);
}

void rectangle::setRectangle(float x, float y, float width, float height)
{
    int windowWidth, windowHeight;
    glfwGetWindowSize(activeWindow, &windowWidth, &windowHeight);

    windowX1 = x;
    windowX2 = x+width;
    windowY1 = y;
    windowY2 = y+height;

    x1 = (GLfloat)x*2/windowWidth;
    x2 = (GLfloat)(x+width)*2/windowWidth;
    y1 = (GLfloat)y*2/windowHeight*-1;
    y2 = (GLfloat)(y+height)*2/windowHeight*-1;

    vertices = std::vector <GLfloat>
    {
        x1,  y1,
        x2,  y1,
        x1,  y2,
        x2,  y2,
        x2,  y1,
        x1,  y2
    };

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

    uvs = std::vector <GLfloat>
    {
        0.0f, 0.0f,
        1.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 1.0f
    };

    glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size()*sizeof(GLfloat), &uvs[0], GL_STATIC_DRAW);
}

bool rectangle::mouseOver()
{
    double mousePosX, mousePosY;
    glfwGetCursorPos(activeWindow, &mousePosX, &mousePosY);
    if (mousePosX < windowX2 && mousePosX > windowX1 && mousePosY < windowY2 && mousePosY > windowY1)
    {
        return true;
    }
    else return false;
}