#ifndef TEXTURE_H
#define TEXTURE_H
#define GLEW_STATIC
#include <GL/glew.h>

#include <FreeImage.h>

#include <iostream>

class texture
{
    public:
        texture();
        texture(GLuint *texture);
        texture(std::string fileName, GLuint *texture);

        GLuint load(std::string fileName, bool flipped = false);

        void flip();
        void setWrap(int type);

        unsigned char* getBitData();

        GLuint getEmptyTexture();
        GLuint getTexture();

        void destroy();

        virtual ~texture();
    protected:
    private:

        void generateEmptyTexture();

        FIBITMAP *pImage;
        int width, height;
        GLint wrapType = GL_REPEAT;

        GLuint tex;
        GLuint emptyTex;

};

#endif // TEXTURE_H
