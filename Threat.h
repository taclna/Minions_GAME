#pragma once
#include "ALL.h"
#include "Texture.h"
class Threat
{
public:
    Threat();
    // Moves the dot
    void move();

    // Shows the dot on the screen relative to the camera
    void render(int camX, int camY, SDL_Rect *clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    // Position accessors
    int getPosX();
    int getPosY();

    void setPosX(int x);
    void setPosY(int y);
    void setFlip(SDL_RendererFlip xFlip);

    SDL_Rect getLocation();

    int getLevel();

    SDL_RendererFlip getFlip();

    void setNumOfCharacter(int x);

    int getNumOfCharacter();

    void characterReset();

private:
    int Fish_WIDTH = 119;
    int Fish_HETGHT = 116;

    // The X and Y offsets of the dot
    int mPosX, mPosY;

    // The velocity of the dot
    int mVelX, mVelY;

    int cnt;

    SDL_RendererFlip flipFish;

    int level = 10;

    SDL_Rect locationFish;

    int NUM_OF_CHARACTER;

    LTexture gTextureTextLevel;

    std::string textLevel;

    SDL_Color textColor;
};