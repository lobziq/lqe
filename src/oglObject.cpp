#include "oglObject.h"

oglObject::oglObject(GLFWwindow *window)
{
    activeWindow = window;
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &textureBuffer);
}

void oglObject::setTexture(std::string fileName, bool flipped)
{
    //glBindTexture(GL_TEXTURE_2D, tex);
    tex = image.load(fileName, !flipped);
}

void oglObject::setTextureWrap(int type)
{
    image.setWrap(type);
    tex = image.getTexture();
}

void oglObject::setColor(float red, float green, float blue)
{
    r = red;
    g = green;
    b = blue;
    glUniform4f(uniColor, r, g, b, 0.0f);
}

void oglObject::useTextures()
{
    glUseProgram(shaderProgram);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
    glUniform1i(uniTexture, 0);
}

void oglObject::useAttributes(int dimensions)
{
    posAttribute = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttribute);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(posAttribute, dimensions, GL_FLOAT, GL_FALSE, dimensions * sizeof(GLfloat), 0);

    texAttribute = glGetAttribLocation(shaderProgram, "uvPosition");
    glEnableVertexAttribArray(texAttribute);
    glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
    glVertexAttribPointer(texAttribute, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);

    glDrawArrays(GL_TRIANGLES, 0, vertices.size()/dimensions);

    glDisableVertexAttribArray(texAttribute);
    glDisableVertexAttribArray(posAttribute);
}

void oglObject::draw()
{
    useTextures();
    setColor(r,g,b);
    useAttributes(2);
}

void oglObject::destroy()
{
    glDeleteProgram(shaderProgram);

    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &textureBuffer);

    glDeleteTextures(1, &tex);

    vertices.clear();
    uvs.clear();
}


oglObject::~oglObject()
{
    //dtor
}
