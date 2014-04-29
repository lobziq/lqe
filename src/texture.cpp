#include "texture.h"

#include <iostream>
#include <FreeImage.h>

texture::texture()
{

}

texture::texture(std::string fileName, GLuint *texture)
{
    load(fileName);
    *texture = tex;
}

GLuint texture::load(std::string fileName, bool flipped)
{
    FIBITMAP* bitmap = FreeImage_Load(FreeImage_GetFileType(fileName.c_str(), 0), fileName.c_str());

    pImage = FreeImage_ConvertTo32Bits(bitmap);
    width = FreeImage_GetWidth(pImage);
    height = FreeImage_GetHeight(pImage);

    if (flipped) FreeImage_FlipVertical(pImage);

    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
    0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

    FreeImage_Unload(bitmap);

    return tex;
}

void texture::setWrap(int type)
{
    wrapType = GL_REPEAT;
}


unsigned char* texture::getBitData()
{
    return FreeImage_GetBits(pImage);
}

texture::texture(GLuint* texture)
{
    generateEmptyTexture();
    *texture = emptyTex;
}

GLuint texture::getEmptyTexture()
{
    generateEmptyTexture();
    return emptyTex;
}

void texture::flip()
{

}


void texture::generateEmptyTexture()
{
    glGenTextures(1, &emptyTex);
    glBindTexture(GL_TEXTURE_2D, emptyTex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    float pixels[] =
    {
        1.0f, 1.0f, 1.0f
    };

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_FLOAT, pixels);
}


GLuint texture::getTexture()
{
    glBindTexture(GL_TEXTURE_2D, tex);

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapType);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapType);

    return tex;
}

void texture::destroy()
{
    FreeImage_Unload(pImage);
}


texture::~texture()
{
    //dtor
}
