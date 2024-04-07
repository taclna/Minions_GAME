#pragma once
#include "ALL.h"
#include "Texture.h"
class Threat
{
public:
    static const int BlueFish_WIDTH = 128;
    static const int BlueFish_HETGHT = 128;
    Threat();
    // Moves the dot
    void move();

    // Shows the dot on the screen relative to the camera
    void render(int camX, int camY, SDL_Rect *clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    // Position accessors
    int getPosX();
    int getPosY();

private:
    // The X and Y offsets of the dot
    int mPosX, mPosY;

    // The velocity of the dot
    int mVelX, mVelY;

    bool left;
    int cnt;
};