#include "Threat.h"
Threat::Threat()
{
    // Initialize the offsets
    mPosX = rand() % 2 == 0 ? 0 - Fish_WIDTH : LEVEL_WIDTH;
    if (mPosX == 0 - Fish_WIDTH)
    {
        flipFish = SDL_FLIP_HORIZONTAL;
    }
    else
    {
        flipFish = SDL_FLIP_NONE;
    }
    mPosY = rand() % (LEVEL_HEIGHT - Fish_HETGHT);
    locationFish = {mPosX, mPosY, Fish_WIDTH, Fish_HETGHT};

    // Initialize the velocity
    mVelX = 1;
    mVelY = 1;

    cnt = 0;

    textLevel = "LEVEL.  10";
}
void Threat::move()
{
    cnt++;
    if (cnt == 500 && NUM_OF_CHARACTER != NUM_MINIONS_CHOOSE)
    {
        if (rand() % 2 == 0)
        {
            flipFish = SDL_FLIP_HORIZONTAL;
        }
        else
        {
            flipFish = SDL_FLIP_NONE;
        }
        cnt = 0;
    }
    // Move the dot left or right
    mPosX -= mVelX * (flipFish == SDL_FLIP_NONE ? 1 : -1);

    // If the dot went too far to the left or right
    if (mPosX + Fish_WIDTH < 0)
    {
        // Move back
        if (NUM_OF_CHARACTER == NUM_MINIONS_CHOOSE)
        {
            NUM_MINIONS_CHOOSE = -1;
        }
        mPosX = rand() % 2 == 0 ? 0 - Fish_WIDTH : LEVEL_WIDTH;
        if (mPosX == 0 - Fish_WIDTH)
        {
            flipFish = SDL_FLIP_HORIZONTAL;
        }
        else
        {
            flipFish = SDL_FLIP_NONE;
        }
        mPosY = rand() % (LEVEL_HEIGHT - Fish_HETGHT);
    }
    if (mPosX > LEVEL_WIDTH)
    {
        // Move back
        mPosX = rand() % 2 == 0 ? 0 - Fish_WIDTH : LEVEL_WIDTH;
        if (NUM_OF_CHARACTER == NUM_MINIONS_CHOOSE)
        {
            NUM_MINIONS_CHOOSE = -1;
        }
        if (mPosX == 0 - Fish_WIDTH)
        {
            flipFish = SDL_FLIP_HORIZONTAL;
        }
        else
        {
            flipFish = SDL_FLIP_NONE;
        }
        mPosY = rand() % (LEVEL_HEIGHT - Fish_HETGHT);
    }
    locationFish = {mPosX, mPosY, Fish_WIDTH, Fish_HETGHT};

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

    if (timeStartedGame != -1)
        gTextureTextLevel.render(camX + (Fish_WIDTH - gTextureTextLevel.getWidth()) / 2, camY + Fish_HETGHT + 3);
    gBlueFishTexture.render(camX, camY, clip, 0.0, NULL, flipFish);
}

int Threat::getPosX()
{
    return mPosX;
}

int Threat::getPosY()
{
    return mPosY;
}

SDL_Rect Threat::getLocation()
{
    return locationFish;
}

int Threat::getLevel()
{
    return level;
}

SDL_RendererFlip Threat::getFlip()
{
    return flipFish;
}

void Threat::setNumOfCharacter(int x)
{
    NUM_OF_CHARACTER = x;
}

int Threat::getNumOfCharacter()
{
    return NUM_OF_CHARACTER;
}

void Threat::setPosX(int x)
{
    mPosX = x;
}

void Threat::setPosY(int y)
{
    mPosY = y;
}

void Threat::setFlip(SDL_RendererFlip xFlip)
{
    flipFish = xFlip;
}

void Threat::characterReset()
{
    // Initialize the offsets
    mPosX = rand() % 2 == 0 ? 0 - Fish_WIDTH : LEVEL_WIDTH;
    if (mPosX == 0 - Fish_WIDTH)
    {
        flipFish = SDL_FLIP_HORIZONTAL;
    }
    else
    {
        flipFish = SDL_FLIP_NONE;
    }
    mPosY = rand() % (LEVEL_HEIGHT - Fish_HETGHT);
    locationFish = {mPosX, mPosY, Fish_WIDTH, Fish_HETGHT};
}