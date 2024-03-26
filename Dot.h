#pragma once
#include "ALL.h"
#include "Texture.h"
class Dot
{
public:
    // The dimensions of the dot
    static const int DOT_WIDTH = 32;
    static const int DOT_HEIGHT = 32;

    // Maximum axis velocity of the dot
    static const int DOT_VEL = 5;

    // Initializes the variables
    Dot();

    // Takes key presses and adjusts the dot's velocity
    void handleEvent(SDL_Event &e);

    // Moves the dot
    void move();

    // Shows the dot on the screen relative to the camera
    void render(int camX, int camY);

    // Position accessors
    int getPosX();
    int getPosY();

private:
    // The X and Y offsets of the dot
    int mPosX, mPosY;

    // The velocity of the dot
    int mVelX, mVelY;
};