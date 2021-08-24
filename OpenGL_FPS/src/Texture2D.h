#pragma once

/*
    Taken from learnopengl.com - in practice
    https://learnopengl.com/code_viewer_gh.php?code=src/7.in_practice/3.2d_game/0.full_source/texture.h
*/
class Texture2D
{
    unsigned int id;
public:
    // holds the ID of the texture object, used for all texture operations to reference to this particlar texture
    // texture image dimensions
    unsigned int Width, Height; // width and height of loaded image in pixels
    // texture Format
    unsigned int Internal_Format; // format of texture object
    unsigned int Image_Format; // format of loaded image
    // texture configuration
    unsigned int Wrap_S; // wrapping mode on S axis
    unsigned int Wrap_T; // wrapping mode on T axis
    unsigned int Filter_Min; // filtering mode if texture pixels < screen pixels
    unsigned int Filter_Max; // filtering mode if texture pixels > screen pixels

    //multi texture coord
    unsigned int Tile_Width, Tile_Height;
    unsigned int Tile_Column, Tile_Row;
    unsigned int Tile_Selected;
    float Text_Coords[8] = { 0 };

    // constructor (sets default texture modes)
    Texture2D();
    ~Texture2D();
    // generates texture from image data
    void Generate(unsigned int width, unsigned int height, unsigned char* data);
    void Generate(unsigned int width, unsigned int height, unsigned int w_tile, unsigned int h_tile, unsigned char* data);
    void UpdateTexCoord();

    // binds the texture as the current active GL_TEXTURE_2D texture object
    void Bind() const;
    void UnBind() const;
};
