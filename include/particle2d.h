#ifndef PARTICLE2D_H
#define PARTICLE2D_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

class particle2d
{
    public:
        particle2d();
        particle2d(glm::vec2 location);
        particle2d(int x, int y);

        void setPosition(int x, int y);
        void setPosition(glm::vec2 position);
        void setSpeed(glm::vec2 speed);
        void setSpeed(float sx, float sy);

        void computePosition();

        int computeSum();

        glm::vec2 getPosition();
        glm::vec2 getSpeed();

        virtual ~particle2d();
    protected:
    private:
        float gravity = 9.8;
        //std::vector <glm::vec2> forces;
        float speedx, speedy;
        float x, y;
};

#endif // PARTICLE2D_H
