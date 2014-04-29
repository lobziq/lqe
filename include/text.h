#ifndef TEXT_H
#define TEXT_H
#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>

class text
{
    public:
        text();
        text(std::string fontName, std::string text, int height = 48);

        void load(std::string fontName, std::string text, int height = 48);

        GLuint getTexture();

        virtual ~text();
    protected:
    private:
        GLuint tex;
};

#endif // TEXT_H
