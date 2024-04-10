#include "Dot.h"

SDL_Rect gMinionsClips[4];
void setMinionsAnimation()
{
    gMinionsClips[0].x = 0;
    gMinionsClips[0].y = 0;
    gMinionsClips[0].w = 32;
    gMinionsClips[0].h = 32;

    gMinionsClips[1].x = 32;
    gMinionsClips[1].y = 0;
    gMinionsClips[1].w = 32;
    gMinionsClips[1].h = 32;

    gMinionsClips[2].x = 64;
    gMinionsClips[2].y = 0;
    gMinionsClips[2].w = 32;
    gMinionsClips[2].h = 32;

    gMinionsClips[3].x = 96;
    gMinionsClips[3].y = 0;
    gMinionsClips[3].w = 32;
    gMinionsClips[3].h = 32;
}
Dot::Dot()
{
    // Initialize the offsets
    mPosX = SCREEN_WIDTH / 2;
    mPosY = SCREEN_HEIGHT / 2;

    // Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    frame = 0;

    locationMinions = {mPosX, mPosY, DOT_WIDTH, DOT_HEIGHT};
}

void Dot::handleEvent(SDL_Event &e)
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
            FlipMinions = SDL_FLIP_NONE;
            mVelX -= DOT_VEL;
            break;
        case SDLK_RIGHT:
            FlipMinions = SDL_FLIP_HORIZONTAL;
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

    locationMinions = {mPosX, mPosY, DOT_WIDTH, DOT_HEIGHT};
}

void Dot::render(int camX, int camY, SDL_Rect *clip, SDL_RendererFlip flip)
{
    // Show the dot relative to the camera
    SDL_Rect *currentClip = &gMinionsClips[frame / 4];
    gDotTexture.render(camX, camY, currentClip, 0.0, NULL, FlipMinions);
    ++frame;
    if (frame / 4 >= 4)
    {
        frame = 0;
    }
}

int Dot::getPosX()
{
    return mPosX;
}

int Dot::getPosY()
{
    return mPosY;
}

SDL_Rect Dot::getLocation()
{
    return locationMinions;
}

int Dot::getLevel()
{
    return level;
}

SDL_RendererFlip Dot::getFlip()
{
    return FlipMinions;
}