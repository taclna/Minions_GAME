#include "Threat.h"
Threat::Threat()
{
    // Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    // Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}
void Threat::move()
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

void Threat::render(int camX, int camY, SDL_Rect *clip, SDL_RendererFlip flip)
{
    gBlueFishTexture.render(camX, camY, clip, 0.0, NULL, flip);
}

int Threat::getPosX()
{
    return mPosX;
}

int Threat::getPosY()
{
    return mPosY;
}