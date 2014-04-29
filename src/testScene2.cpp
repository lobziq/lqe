#include "testScene2.h"


#include <stdlib.h>
#include <time.h>
#include "particleDrawer.h"


testScene2::testScene2(GLFWwindow* window): scene(window)
{
    backgroundR = 0.5;
    backgroundG = 0.5;
    backgroundB = 0.5;
    int w, h;
    glfwGetWindowSize(window, &w, &h);
    std::vector <float> c;
    srand(time(NULL));
    for (int i = 0; i < 3000; i++)
    {
        c.push_back(rand()%w);
        c.push_back(rand()%h);
    }

    particleDrawer *pd = new particleDrawer(window);
    pd->fillBufferWithParticles(c);
    interface.push_back(pd);
}

testScene2::~testScene2()
{
    //dtor
}
