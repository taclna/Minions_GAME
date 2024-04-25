#pragma once
#include "ALL.h"
#include "Texture.h"
#include "TimeAndLevel.h"

class ThreatBigFish
{
public:
    ThreatBigFish();
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
    int getType();

    void characterReset();

private:
    int Fish_WIDTH = 400;
    int Fish_HETGHT = 159;
    const int level = 100;

    // The X and Y offsets of the dot
    int mPosX, mPosY;

    // The velocity of the dot
    int mVelX, mVelY;

    SDL_RendererFlip flipFish;
    int cnt;
    int frame;

    SDL_Rect locationFish;

    int NUM_OF_CHARACTER;

    LTexture gTextureTextLevel;

    std::string textLevel;

    SDL_Color textColor;

    int type;
};