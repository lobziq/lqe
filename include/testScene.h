#ifndef TESTSCENE_H
#define TESTSCENE_H

#include <scene.h>
#include <model.h>
#include <particleDrawer.h>


class testScene : public scene
{
    public:
        testScene(GLFWwindow *window);
        virtual ~testScene();
    protected:
    private:
};

#endif // TESTSCENE_H
