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
    locationBlueFish = {mPosX, mPosY, BlueFish_WIDTH, BlueFish_HETGHT};

    // Initialize the velocity
    mVelX = 1;
    mVelY = 1;

    cnt = 0;

    textLevel = "LEVEL.  10";
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
    locationBlueFish = {mPosX, mPosY, BlueFish_WIDTH, BlueFish_HETGHT};

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

    gTextureTextLevel.render(camX + (BlueFish_WIDTH - gTextureTextLevel.getWidth()) / 2, camY + BlueFish_HETGHT + 3);
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

SDL_Rect Threat::getLocation()
{
    return locationBlueFish;
}

int Threat::getLevel()
{
    return level;
}

SDL_RendererFlip Threat::getFlip()
{
    return flipBlueFish;
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
    flipBlueFish = xFlip;
}