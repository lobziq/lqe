#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "app.h"

int main()
{
    app game("lobziq app", 1280, 720);
    game.render();
    game.shutDown();
    return 0;
}
