#ifndef CAMERA_H
#define CAMERA_H
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class camera
{
    public:
        camera();
        void computeMatricesFromInputs(GLFWwindow *window);
        void strategyCamera(GLFWwindow *window);

        glm::mat4 getProjectionMatrix();
        glm::mat4 getViewMatrix();

        virtual ~camera();
    protected:
    private:

        //void scroll(GLFWwindow* window, double x, double y);

        glm::mat4 ViewMatrix;
        glm::mat4 ProjectionMatrix;
        glm::vec3 position = glm::vec3(0, 10, 5);
        glm::vec3 watchPos = glm::vec3(0, 0, 0);

        float horizontalAngle = 0.0f;
        float verticalAngle = 0.0f;
        float initialFoV = 45.0f;
        float speed = 3.0f;
        float mouseSpeed = 0.005f;
};

#endif // CAMERA_H
