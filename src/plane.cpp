#include "plane.h"
#include "shaderLoader.h"

plane::plane(int pSize, int resolution, GLFWwindow *window, camera *sceneCamera): oglObject3d(window, sceneCamera)
{
    shaderLoader shaders("shaders/object3d.vert", "shaders/object3d.frag", &shaderProgram);

    uniTexture = glGetUniformLocation(shaderProgram, "tex");
    uniColor = glGetUniformLocation(shaderProgram, "color");
    uniMVP = glGetUniformLocation(shaderProgram, "MVP");
    create(pSize, pSize, resolution, resolution);
}

plane::plane(int width, int height, int resolutionX, int resolutionY, GLFWwindow *window, camera *sceneCamera): oglObject3d(window, sceneCamera)
{
    shaderLoader shaders("shaders/object3d.vert", "shaders/object3d.frag", &shaderProgram);

    uniTexture = glGetUniformLocation(shaderProgram, "tex");
    uniColor = glGetUniformLocation(shaderProgram, "color");
    uniMVP = glGetUniformLocation(shaderProgram, "MVP");
    create(width, height, resolutionX, resolutionY);
}

void plane::create(int width, int height, int resolutionX, int resolutionY)
{
    for (int i = 0; i < resolutionX; i++)
    {
        for (int j = 0; j < resolutionY; j++)
        {
            //1 точка 1 треугольника
            vertices.push_back((GLfloat)i*width/resolutionX);
            vertices.push_back((GLfloat)0);
            vertices.push_back((GLfloat)j*height/resolutionY);
            //2 точка 1 треугольника
            vertices.push_back((GLfloat)(i+1)*width/resolutionX);
            vertices.push_back((GLfloat)0);
            vertices.push_back((GLfloat)j*height/resolutionY);
            //3 точка 1 треугольника
            vertices.push_back((GLfloat)i*width/resolutionX);
            vertices.push_back((GLfloat)0);
            vertices.push_back((GLfloat)(j+1)*height/resolutionY);
            //1 точка 2 треугольника
            vertices.push_back((GLfloat)(i+1)*width/resolutionX);
            vertices.push_back((GLfloat)0);
            vertices.push_back((GLfloat)j*height/resolutionY);
            //2 точка 2 треугольника
            vertices.push_back((GLfloat)i*width/resolutionX);
            vertices.push_back((GLfloat)0);
            vertices.push_back((GLfloat)(j+1)*height/resolutionY);
            //3 точка 2 треугольника
            vertices.push_back((GLfloat)(i+1)*width/resolutionX);
            vertices.push_back((GLfloat)0);
            vertices.push_back((GLfloat)(j+1)*height/resolutionY);

            //1 точка 1 треугольника
            uvs.push_back((GLfloat)i*1);
            uvs.push_back((GLfloat)j*1);
            //2 точка 1 треугольника
            uvs.push_back((GLfloat)(i+1)*1);
            uvs.push_back((GLfloat)j*1);
            //3 точка 1 треугольника
            uvs.push_back((GLfloat)i*1);
            uvs.push_back((GLfloat)(j+1)*1);
            //1 точка 2 треугольника
            uvs.push_back((GLfloat)(i+1)*1);
            uvs.push_back((GLfloat)j*1);
            //2 точка 2 треугольника
            uvs.push_back((GLfloat)i*1);
            uvs.push_back((GLfloat)(j+1)*1);
            //3 точка 2 треугольника
            uvs.push_back((GLfloat)(i+1)*1);
            uvs.push_back((GLfloat)(j+1)*1);
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size()*sizeof(GLfloat), &uvs[0], GL_STATIC_DRAW);
}

void plane::setDepthTexture(std::string fileName)
{
    //depthTex.load("darkritual.gif");
    //d = depthTex.getBitData();
    //for (int i = 0; i < sizeof(depthTex)/sizeof(unsigned char); i++)
    //{
        //std::cout << d[i] << std::endl;
    //}
}


plane::~plane()
{
    //dtor
}
