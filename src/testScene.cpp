#include "testScene.h"
#include "model.h"
#include "rectangle.h"
#include "plane.h"
#include "particleDrawer.h"

#include <stdlib.h>
#include <time.h>
#include <math.h>

testScene::testScene(GLFWwindow* window): scene(window)
{
    int w, h;
    glfwGetWindowSize(window, &w, &h);

    interface.push_back(new rectangle(w/2-200, h/2-105, 200, 200, window));
    interface.back()->setTexture("textures/doge.png");

    //backgroundR = 0.5;
    //backgroundG = 0.5;
    //backgroundB = 0.5;
    /*
    interface.push_back(new rectangle(w/2+5, h/2-100, 200, 40, window));
    interface.back()->setText("tahoma.ttf", "SUCH");
    interface.push_back(new rectangle(w/2+5, h/2-50, 200, 40, window));
    interface.back()->setText("arial.ttf", "TEXT");
    interface.push_back(new rectangle(w/2+5, h/2, 200, 40, window));
    interface.back()->setText("The Amazing Spider-Man.ttf", "MUCH");
    interface.push_back(new rectangle(w/2+5, h/2+50, 200, 40, window));
    interface.back()->setText("AVENGEANCE HEROIC AVENGER.ttf", "WOW");

    particleDrawer pDrawer(window);
    //pDrawer.fillBufferWithParticles(someParticles);
    //add2d(pDrawer);*/

    //std::cout << "the amount of 2d objecs scene contain is " << interface.size() << std::endl;
}

void scene::update()
{
    static double lastTime = glfwGetTime();

    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);
}

testScene::~testScene()
{
    //dtor
}
