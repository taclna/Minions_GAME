#include "Threat.h"
Threat::Threat()
{
    // Initialize the offsets
    mPosX = rand() % 2 == 0 ? 0 - BlueFish_WIDTH : LEVEL_WIDTH;
    if (mPosX == 0 - BlueFish_WIDTH)
    {
        flipBlueFish = SDL_FLIP_HORIZONTAL;
    }
    else
    {
        flipBlueFish = SDL_FLIP_NONE;
    }
    mPosY = rand() % (LEVEL_HEIGHT - BlueFish_HETGHT);

    // Initialize the velocity
    mVelX = 1;
    mVelY = 1;

    cnt = 0;
}
void Threat::move()
{
    cnt++;
    if (cnt == 500)
    {
        if (rand() % 2 == 0)
        {
            flipBlueFish = SDL_FLIP_HORIZONTAL;
        }
        else
        {
            flipBlueFish = SDL_FLIP_NONE;
        }
        cnt = 0;
    }
    // Move the dot left or right
    mPosX -= mVelX * (flipBlueFish == SDL_FLIP_NONE ? 1 : -1);

    // If the dot went too far to the left or right
    if (mPosX + BlueFish_WIDTH < 0)
    {
        // Move back
        mPosX = rand() % 2 == 0 ? 0 - BlueFish_WIDTH : LEVEL_WIDTH;
        if (mPosX == 0 - BlueFish_WIDTH)
        {
            flipBlueFish = SDL_FLIP_HORIZONTAL;
        }
        else
        {
            flipBlueFish = SDL_FLIP_NONE;
        }
        mPosY = rand() % (LEVEL_HEIGHT - BlueFish_HETGHT);
    }
    if (mPosX > LEVEL_WIDTH)
    {
        // Move back
        mPosX = rand() % 2 == 0 ? 0 - BlueFish_WIDTH : LEVEL_WIDTH;
        if (mPosX == 0 - BlueFish_WIDTH)
        {
            flipBlueFish = SDL_FLIP_HORIZONTAL;
        }
        else
        {
            flipBlueFish = SDL_FLIP_NONE;
        }
        mPosY = rand() % (LEVEL_HEIGHT - BlueFish_HETGHT);
    }

    // // Move the dot up or down
    // mPosY += mVelY;

    // // If the dot went too far up or down
    // if ((mPosY < 0) || (mPosY + DOT_HEIGHT > LEVEL_HEIGHT))
    // {
    //     // Move back
    //     mPosY -= mVelY;
    // }
}

void Threat::render(int camX, int camY, SDL_Rect *clip, SDL_RendererFlip flip)
{
    gBlueFishTexture.render(camX, camY, clip, 0.0, NULL, flipBlueFish);
}

int Threat::getPosX()
{
    return mPosX;
}

int Threat::getPosY()
{
    return mPosY;
}