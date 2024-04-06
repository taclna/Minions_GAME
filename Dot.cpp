#include "Dot.h"

Dot::Dot()
{
    // Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    // Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Dot::handleEvent(SDL_Event &e, SDL_RendererFlip &flip)
{
    // If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        // Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            mVelY -= DOT_VEL;
            break;
        case SDLK_DOWN:
            mVelY += DOT_VEL;
            break;
        case SDLK_LEFT:
            flip = SDL_FLIP_HORIZONTAL;
            mVelX -= DOT_VEL;
            break;
        case SDLK_RIGHT:
            flip = SDL_FLIP_NONE;
            mVelX += DOT_VEL;
            break;
        }
    }
    // If a key was released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        // Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            mVelY += DOT_VEL;
            break;
        case SDLK_DOWN:
            mVelY -= DOT_VEL;
            break;
        case SDLK_LEFT:
            mVelX += DOT_VEL;
            break;
        case SDLK_RIGHT:
            mVelX -= DOT_VEL;
            break;
        }
    }
}

void Dot::move()
{
    // Move the dot left or right
    mPosX += mVelX;

    // If the dot went too far to the left or right
    if ((mPosX < 0) || (mPosX + DOT_WIDTH > LEVEL_WIDTH))
    {
        // Move back
        mPosX -= mVelX;
    }

    // Move the dot up or down
    mPosY += mVelY;

    // If the dot went too far up or down
    if ((mPosY < 0) || (mPosY + DOT_HEIGHT > LEVEL_HEIGHT))
    {
        // Move back
        mPosY -= mVelY;
    }
}

void Dot::render(int camX, int camY, SDL_Rect *clip, SDL_RendererFlip flip)
{
    // Show the dot relative to the camera
    gDotTexture.render(mPosX - camX, mPosY - camY, clip, 0.0, NULL, flip);
}

int Dot::getPosX()
{
    return mPosX;
}

int Dot::getPosY()
{
    return mPosY;
}