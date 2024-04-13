#pragma once
#include "ALL.h"
#include "Texture.h"
void setMinionsAnimation();
class Dot
{
public:
    // Maximum axis velocity of the dot
    static const int DOT_VEL = 3;

    static const int Minions_WIDTH = 26;
    static const int Minions_HEIGHT = 32;

    // Initializes the variables
    Dot();

    // Takes key presses and adjusts the dot's velocity
    void handleEvent(SDL_Event &e);

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
    void setLevel(int mLevel);

    SDL_RendererFlip getFlip();

    void characterReset();

private:
    // The X and Y offsets of the dot
    int mPosX, mPosY;

    // The velocity of the dot
    int mVelX, mVelY;

    int DOT_WIDTH = 26;
    int DOT_HEIGHT = 32;

    int frame;

    SDL_RendererFlip FlipMinions = SDL_FLIP_NONE;

    SDL_Rect locationMinions;

    int level = 1;
};