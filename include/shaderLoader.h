#ifndef SHADERLOADER_H
#define SHADERLOADER_H
#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>

class shaderLoader
{
    public:
        shaderLoader();
        shaderLoader(std::string vertFile, std::string fragFile);
        shaderLoader(std::string vertFile, std::string fragFile, GLint *shaderProgram);

        void load(std::string vertFile, std::string fragFile);
        GLint getProgram();

        virtual ~shaderLoader();
    protected:
    private:
        std::string path;
        GLint program;
};

#endif // SHADERLOADER_H
