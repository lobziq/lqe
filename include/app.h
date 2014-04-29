#ifndef APP_H
#define APP_H

#include <GLFW/glfw3.h>
#include <iostream>

#include "scene.h"

class app
{
    public:
        app();
        app(std::string title, int width, int height);
        void countFPS(std::string* fpscount);

        //void setScene(scene* appScene);

        void render();
        void shutDown();
        virtual ~app();
    protected:
    private:
        std::string appName;

        double timeCoefficient = 0;
        double framesPerSecond = 0;
        double lastTime = 0;
        GLFWwindow* window;
};

#endif // APP_H
