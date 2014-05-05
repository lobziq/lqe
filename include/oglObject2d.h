#ifndef OGLOBJECT2D_H
#define OGLOBJECT2D_H
#define GLEW_STATIC
#include <GL/glew.h>

#include <oglObject.h>
#include <GLFW/glfw3.h>

class oglObject2d : public oglObject
{
    public:
        oglObject2d(GLFWwindow *window);

        void setPosition(int x, int y);
    protected:
    private:
};

#endif // OGLOBJECT2D_H
