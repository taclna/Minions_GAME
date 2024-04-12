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
    locationRedFish = {mPosX, mPosY, RedFish_WIDTH, RedFish_HETGHT};

    // Initialize the velocity
    mVelX = 2;
    mVelY = 1;
    cnt = 0;
    frame = 0;

    textLevel = "LEVEL.  5";
}
void ThreatRedFish::move()
{
    cnt++;
    if (cnt == 500 && NUM_OF_CHARACTER != NUM_MINIONS_CHOOSE)
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
        if (NUM_OF_CHARACTER == NUM_MINIONS_CHOOSE)
        {
            NUM_MINIONS_CHOOSE = -1;
        }

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
        if (NUM_OF_CHARACTER == NUM_MINIONS_CHOOSE)
        {
            NUM_MINIONS_CHOOSE = -1;
        }

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
    locationRedFish = {mPosX, mPosY, RedFish_WIDTH, RedFish_HETGHT};

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
    if (levelMinions >= level)
    {
        textColor = {0, 205, 0};
    }
    else
    {
        textColor = {255, 0, 0};
    }
    if (!gTextureTextLevel.loadFromRenderedText(gFontTextLevel, textLevel, textColor))
    {
        cout << "khong load duoc gTextureTextLevel" << endl;
    }

    gTextureTextLevel.render(camX + (RedFish_WIDTH - gTextureTextLevel.getWidth()) / 2, camY + RedFish_HETGHT + 3);
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

SDL_Rect ThreatRedFish::getLocation()
{
    return locationRedFish;
}

int ThreatRedFish::getLevel()
{
    return level;
}

SDL_RendererFlip ThreatRedFish::getFlip()
{
    return flipRedFish;
}

void ThreatRedFish::setNumOfCharacter(int x)
{
    NUM_OF_CHARACTER = x;
}

int ThreatRedFish::getNumOfCharacter()
{
    return NUM_OF_CHARACTER;
}

void ThreatRedFish::setPosX(int x)
{
    mPosX = x;
}

void ThreatRedFish::setPosY(int y)
{
    mPosY = y;
}

void ThreatRedFish::setFlip(SDL_RendererFlip xFlip)
{
    flipRedFish = xFlip;
}