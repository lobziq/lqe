#ifndef MODEL_H
#define MODEL_H

#include <oglObject3d.h>


class model : public oglObject3d
{
    public:
        model();
        model(GLFWwindow *window, camera *sceneCamera);

        void load(std::string fileName);

    protected:
    private:
};

#endif // MODEL_H
