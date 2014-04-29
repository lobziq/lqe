#include "scene.h"

#include <GLFW/glfw3.h>
#include <vector>



scene::scene(GLFWwindow *window)
{
    this->window = window;
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
}

void scene::render()
{
    glClearColor(backgroundR, backgroundG, backgroundB, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    update();
    sceneCamera.strategyCamera(window);
    for (int i=0; i < interface.size(); i++)
    {
        interface[i]->draw();
    }
    for (int j=0; j < meshes.size(); j++)
    {
        meshes[j]->draw();
    }
}

void scene::add3d(oglObject3d obj3d)
{
    //meshes.push_back(new oglObject3d);
}

void scene::add2d(oglObject2d obj2d)
{
    //interface.push_back(new oglObject2d(window));
}

void scene::clean()
{
    for (int i=0; i < interface.size(); i++)
    {
        interface[i]->destroy();
    }
    for (int j=0; j < meshes.size(); j++)
    {
        meshes[j]->destroy();
    }
}


scene::~scene()
{
    //dtor
}
