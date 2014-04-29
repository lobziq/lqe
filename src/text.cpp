#include "text.h"

#include <iostream>
#include <algorithm>

#include <ft2build.h>
#include FT_FREETYPE_H

text::text()
{

}

text::text(std::string fontName, std::string text, int height)
{
    load(fontName, text);
}

void text::load(std::string fontName, std::string text, int height)
{
    FT_Library ft;

    if(FT_Init_FreeType(&ft))
    {
        std::cout <<  "Could not init freetype library" << std::endl;
        //return 1;
    }

    FT_Face face;

    if(FT_New_Face(ft, fontName.c_str(), 0, &face))
    {
        std::cout << "Could not open font" << std::endl;
        //return 1;
    }
    FT_Set_Pixel_Sizes(face, 0, height);

    if(FT_Load_Char(face, 'G', FT_LOAD_RENDER))
    {
        std::cout << "Could not load character 'X'" << std::endl;
    }

    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    FT_GlyphSlot g = face->glyph;

    int w = 0;
    int h = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if(FT_Load_Char(face, text.at(i), FT_LOAD_RENDER))
        {
            std::cout << "Could not load character " << text.at(i) << std::endl;
        }
        w += g->bitmap.width;
        h = std::max(h, g->bitmap.rows);
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, w, h, 0, GL_ALPHA, GL_UNSIGNED_BYTE, 0);

    int x = 0;

    for(int i = 0; i < text.size(); i++)
    {
        if(FT_Load_Char(face, text.at(i), FT_LOAD_RENDER))
        continue;

        glTexSubImage2D(GL_TEXTURE_2D, 0, x, 0, g->bitmap.width, g->bitmap.rows, GL_ALPHA, GL_UNSIGNED_BYTE, g->bitmap.buffer);

        x += g->bitmap.width;
    }
}

GLuint text::getTexture()
{
    return tex;
}


text::~text()
{
    //dtor
}
