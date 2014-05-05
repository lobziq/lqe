#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <oglObject2d.h>


class rectangle : public oglObject2d
{
    public:
        rectangle();
        rectangle(int x, int y, int width, int height, GLFWwindow* window);

        void setRectangle(float x, float y, float width, float height);

        bool mouseOver();

        float getPosX();
        float getPosY();
        float getWidth();
        float getHeight();

        void draw();

    protected:
    private:
        float windowX1, windowX2, windowY1, windowY2, x1, x2, y1, y2;
};

#endif // RECTANGLE_H
