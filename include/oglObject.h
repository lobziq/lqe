#ifndef OGLOBJECT_H
#define OGLOBJECT_H
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>
#include <iostream>

#include "texture.h"
#include "text.h"

class oglObject
{
    public:
        oglObject(GLFWwindow *window);

        void setTexture(std::string fileName, bool flipped = false);
        void setTextureWrap(int type);
        void setColor(float red, float green, float blue);



        virtual void draw();
        void destroy();

        virtual ~oglObject();
    protected:
        void useTextures();
        void useAttributes(int dimensions);

        std::vector <GLfloat> vertices;
        std::vector <GLfloat> uvs;

        texture image;
        text textimage;

        GLFWwindow *activeWindow;

        GLint posAttribute;
        GLint texAttribute;
        GLint uniTexture;
        GLint uniColor;

        GLint shaderProgram;

        GLuint tex;
        GLuint vertexBuffer;
        GLuint textureBuffer;

        float r, g, b, transparency;
    private:

};

#endif // OGLOBJECT_H
