#include "ThreatRedFish.h"
SDL_Rect gRedFishClips[2];
void setRedFishAnimation()
{
    gRedFishClips[0].x = 0;
    gRedFishClips[0].y = 0;
    gRedFishClips[0].w = 72;
    gRedFishClips[0].h = 72;

    gRedFishClips[1].x = 72;
    gRedFishClips[1].y = 0;
    gRedFishClips[1].w = 72;
    gRedFishClips[1].h = 72;
}
ThreatRedFish::ThreatRedFish()
{
    // Initialize the offsets
    mPosX = rand() % 2 == 0 ? 0 - RedFish_WIDTH : LEVEL_WIDTH;
    if (mPosX == 0 - RedFish_WIDTH)
    {
        flipRedFish = SDL_FLIP_HORIZONTAL;
    }
    else
    {
        flipRedFish = SDL_FLIP_NONE;
    }
    mPosY = rand() % (LEVEL_HEIGHT - RedFish_HETGHT);

    // Initialize the velocity
    mVelX = 2;
    mVelY = 1;
    cnt = 0;
    frame = 0;
}
void ThreatRedFish::move()
{
    cnt++;
    if (cnt == 500)
    {
        if (rand() % 2 == 0)
        {
            flipRedFish = SDL_FLIP_HORIZONTAL;
        }
        else
        {
            flipRedFish = SDL_FLIP_NONE;
        }
        cnt = 0;
    }
    // Move the dot left or right
    mPosX -= mVelX * (flipRedFish == SDL_FLIP_NONE ? 1 : -1);

    // If the dot went too far to the left or right
    if (mPosX + RedFish_WIDTH < 0)
    {
        // Move back
        mPosX = rand() % 2 == 0 ? 0 - RedFish_WIDTH : LEVEL_WIDTH;
        if (mPosX == 0 - RedFish_WIDTH)
        {
            flipRedFish = SDL_FLIP_HORIZONTAL;
        }
        else
        {
            flipRedFish = SDL_FLIP_NONE;
        }
        mPosY = rand() % (LEVEL_HEIGHT - RedFish_HETGHT);
    }
    if (mPosX > LEVEL_WIDTH)
    {
        // Move back
        mPosX = rand() % 2 == 0 ? 0 - RedFish_WIDTH : LEVEL_WIDTH;
        if (mPosX == 0 - RedFish_WIDTH)
        {
            flipRedFish = SDL_FLIP_HORIZONTAL;
        }
        else
        {
            flipRedFish = SDL_FLIP_NONE;
        }
        mPosY = rand() % (LEVEL_HEIGHT - RedFish_HETGHT);
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

void ThreatRedFish::render(int camX, int camY, SDL_Rect *clip, SDL_RendererFlip flip)
{
    SDL_Rect *currentClip = &gRedFishClips[frame / 16];
    gRedFishTexture.render(camX, camY, currentClip, 0.0, NULL, flipRedFish);
    ++frame;
    if (frame / 16 >= 2)
    {
        frame = 0;
    }
}

int ThreatRedFish::getPosX()
{
    return mPosX;
}

int ThreatRedFish::getPosY()
{
    return mPosY;
}