#pragma once
#include "ALL.h"
class LTexture
{
public:
    // Initializes variables
    LTexture();

    // Deallocates memory
    ~LTexture();

    // Loads image at specified path
    bool loadFromFile(std::string path);

    // Creates image from font string
    bool loadFromRenderedText(TTF_Font *gFont, std::string textureText, SDL_Color textColor);

    // Deallocates texture
    void free();

    // Set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    // Set blending
    void setBlendMode(SDL_BlendMode blending);

    // Set alpha modulation
    void setAlpha(Uint8 alpha);

    // Renders texture at given point
    void render(int x, int y, SDL_Rect *clip = NULL, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    // Gets image dimensions
    int getWidth();
    int getHeight();

    int getPosX();
    int getPosY();

private:
    // The actual hardware texture
    SDL_Texture *mTexture;

    // Image dimensions
    int mWidth;
    int mHeight;

    int mPosX;
    int mPosY;
};
extern LTexture gDotTexture;
extern LTexture gBGTexture;
extern LTexture gBlueFishTexture;
extern LTexture gRedFishTexture;
extern LTexture gBlackBTexture;
extern LTexture gGreyBTexture;
extern LTexture gMenuBackTexture;