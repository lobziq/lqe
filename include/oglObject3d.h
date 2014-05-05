#ifndef OGLOBJECT3D_H
#define OGLOBJECT3D_H

#include <oglObject.h>

#include "camera.h"


class oglObject3d : public oglObject
{
    public:
        oglObject3d(GLFWwindow *window, camera *sceneCamera);

        virtual void load(std::string fileName);

        void setPosition(float x, float y, float z);

        glm::vec3 getPosition();

        void draw();

    protected:

        void useCamera();

        camera *objectCam;

        glm::mat4 projectionMatrix;
        glm::mat4 viewMatrix;
        glm::mat4 modelMatrix;
        glm::mat4 mvpMatrix;

        GLuint uniMVP;

        float x, y, z;
    private:

};

#endif // OGLOBJECT3D_H
