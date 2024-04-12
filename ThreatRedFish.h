#pragma once
#include "ALL.h"
#include "Texture.h"

void setRedFishAnimation();
class ThreatRedFish
{
public:
    ThreatRedFish();
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

private:
    const int RedFish_WIDTH = 72;
    const int RedFish_HETGHT = 72;

    // The X and Y offsets of the dot
    int mPosX, mPosY;

    // The velocity of the dot
    int mVelX, mVelY;

    SDL_RendererFlip flipRedFish;
    int cnt;
    int frame;

    int level = 5;

    SDL_Rect locationRedFish;

    int NUM_OF_CHARACTER;

    LTexture gTextureTextLevel;

    std::string textLevel;

    SDL_Color textColor;
};