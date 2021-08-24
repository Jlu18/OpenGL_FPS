#include "Texture2D.h"
#include "Util.h"
#include <GL/glew.h>

Texture2D::Texture2D()
    : Width(0), Height(0), Internal_Format(GL_RGB), Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR)
    , Tile_Width(0), Tile_Height(0), Tile_Selected(0), Tile_Column(0), Tile_Row(0)
{
    GLCall(glGenTextures(1, &id));
}

void Texture2D::UpdateTexCoord()
{
    //top left ( 0, 1 )
    Text_Coords[0] = 0.0f + (1.0f / Tile_Column * (Tile_Selected % Tile_Column));
    Text_Coords[1] = 1.0f - (1.0f / Tile_Row * int(Tile_Selected / Tile_Column));

    //top right (1, 1)
    Text_Coords[2] = 0.0f + (1.0f / Tile_Column * ((Tile_Selected + 1) % Tile_Column));
    Text_Coords[3] = 1.0f - (1.0f / Tile_Row * int(Tile_Selected / Tile_Column));

    //bottom right (0, 0)
    Text_Coords[4] = 0.0f + (1.0f / Tile_Column * (Tile_Selected % Tile_Column));
    Text_Coords[5] = 1.0f - (1.0f / Tile_Row * int((Tile_Selected + Tile_Column) / Tile_Column));

    //bottom left (0, 1)
    Text_Coords[6] = 0.0f + (1.0f / Tile_Column * ((Tile_Selected + 1) % Tile_Column));
    Text_Coords[7] = 1.0f + (1.0f / Tile_Row * int((Tile_Selected + Tile_Column) / Tile_Column));
}

Texture2D::~Texture2D()
{
    GLCall(glDeleteTextures(1, &id));
}

void Texture2D::Generate(unsigned int width, unsigned int height, unsigned int w_tile, unsigned int h_tile, unsigned char* data) {
    this->Width = width;
    this->Height = height;
    this->Tile_Width = w_tile;
    this->Tile_Height = h_tile;

    this->Tile_Column = Width / Tile_Width;
    this->Tile_Row = Height / Tile_Height;

    // create Texture
    GLCall(glBindTexture(GL_TEXTURE_2D, this->id));
    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, this->Internal_Format, width, height, 0, this->Image_Format, GL_UNSIGNED_BYTE, data));
    // set Texture wrap and filter modes
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max));
    // unbind texture
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));

    UpdateTexCoord();
}

void Texture2D::Generate(unsigned int width, unsigned int height, unsigned char* data)
{
    Generate(width, height, width, height, data);
}

void Texture2D::Bind() const
{
    GLCall(glBindTexture(GL_TEXTURE_2D, id));
}

void Texture2D::UnBind() const
{
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}