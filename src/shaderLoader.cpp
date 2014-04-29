#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>
#include <fstream>

#include "shaderLoader.h"

shaderLoader::shaderLoader()
{
    //ctor
}

shaderLoader::shaderLoader(std::string vertFile, std::string fragFile)
{
    load(vertFile,fragFile);
}

shaderLoader::shaderLoader(std::string vertFile, std::string fragFile, GLint* shaderProgram)
{
    load(vertFile,fragFile);
    *shaderProgram = program;
}

void shaderLoader::load(std::string vertFile, std::string fragFile)
{
    path = "";
    std::string line, vertexShaderCode, fragmentShaderCode;
    std::ifstream shaderFileStream;

    //загружаем вертексный шейдер
    vertFile = path + vertFile;
    shaderFileStream.open(vertFile.c_str());
    if (!shaderFileStream)
    {
        std::cout << "ERROR WITH LOADING FILE " << vertFile << std::endl;
    }
    while(!shaderFileStream.eof())
    {
        getline(shaderFileStream,line);
        vertexShaderCode += line + "\n";
    }
    shaderFileStream.close();
    const char* vertexSource = vertexShaderCode.c_str();

    //загружаем фрагментный шейдер
    fragFile = path + fragFile;
    shaderFileStream.open(fragFile.c_str());
    if (!shaderFileStream)
    {
        std::cout << "ERROR WITH LOADING FILE " << fragFile << std::endl;
    }
    while(!shaderFileStream.eof())
    {
        getline(shaderFileStream,line);
        fragmentShaderCode += line + "\n";
    }
    shaderFileStream.close();
    const char* fragmentSource = fragmentShaderCode.c_str();

    GLint result = GL_FALSE;

    //компилируем шейдеры, проверяем правильно ли они скомпилировались
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        std::cout << "Vertex shader compiling trouble" << std::endl;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        std::cout << "Fragment shader compiling trouble" << std::endl;
    }

    //создаем программу, прикрепляем наши шейдеры
    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    if (result == GL_FALSE)
    {
        std::cout << "Shader program linking trouble" << std::endl;
    }

    //так как программа создана, шейдеры нам больше не нужны
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}


GLint shaderLoader::getProgram()
{
    return program;
}


shaderLoader::~shaderLoader()
{
    //dtor
}
