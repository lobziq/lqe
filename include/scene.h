#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "oglObject2d.h"
#include "oglObject3d.h"
#include "camera.h"
#include "app.h"


class scene
{
    public:
        scene(GLFWwindow *window);

        void update();
        void render();

        void clean();

        void add3d(oglObject3d obj3d);
        void add2d(oglObject2d obj2d);

        virtual ~scene();
    protected:
        std::vector <oglObject2d*> interface;
        std::vector <oglObject3d*> meshes;

        camera sceneCamera;
        GLFWwindow *window;

        float backgroundR = 1.0;
        float backgroundG = 1.0;
        float backgroundB = 1.0;
    private:

};

#endif // SCENE_H
