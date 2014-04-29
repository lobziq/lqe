#ifndef PLANE_H
#define PLANE_H

#include <oglObject3d.h>


class plane : public oglObject3d
{
    public:
        plane();
        plane(GLFWwindow *window, camera *sceneCamera);
        plane(int pSize, int resolution, GLFWwindow *window, camera *sceneCamera);
        plane(int width, int height, int resolutionX, int resolutionY, GLFWwindow *window, camera *sceneCamera);

        void setDepthTexture(std::string fileName);

        void create(int width, int height, int resolutionX, int resolutionY);

        virtual ~plane();
    protected:
    private:
        texture depthTex;
        unsigned char* d;
        std::vector <GLfloat> depth;
        int width, height, resolutionX, resolutionY;

};

#endif // PLANE_H
