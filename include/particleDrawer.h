#ifndef PARTICLEDRAWER_H
#define PARTICLEDRAWER_H

#include "oglObject2d.h"
#include <vector>
#include "particle.h"

class particleDrawer: public oglObject2d
{
    public:
        particleDrawer();
        particleDrawer(GLFWwindow* window);

        void fillBufferWithParticles(std::vector <float> particlesArray);
        void loadShaderProgram();
        void draw();

        virtual ~particleDrawer();
    protected:

    private:
        float data[9];
};

#endif // PARTICLEDRAWER_H
