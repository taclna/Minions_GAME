#include "ThreatBigFish.h"
const int clipWIDTH = 400;
const int clipHEIGHT = 159;
ThreatBigFish::ThreatBigFish()
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

    type = 100;

    textLevel = "LEVEL.  100";
}
void ThreatBigFish::move()
{
    cnt++;
    if (cnt == 600 && NUM_OF_CHARACTER != NUM_MINIONS_CHOOSE)
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
        if (NUM_OF_CHARACTER == NUM_MINIONS_CHOOSE)
        {
            NUM_MINIONS_CHOOSE = -1;
        }

        // Move back
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
        if (NUM_OF_CHARACTER == NUM_MINIONS_CHOOSE)
        {
            NUM_MINIONS_CHOOSE = -1;
        }

        // Move back
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

void ThreatBigFish::render(int camX, int camY, SDL_Rect *clip, SDL_RendererFlip flip)
{
    if (levelMinions >= level)
    {
        textColor = colorGreen;
    }
    else
    {
        textColor = colorRed;
    }
    if (!gTextureTextLevel.loadFromRenderedText(gFontTextLevel, textLevel, textColor))
    {
        cout << "khong load duoc BigFish gTextureTextLevel" << endl;
    }

    if (SCREEN_NOW != NUM_COME_TO_MENU && NUM_MINIONS_CHOOSE != NUM_OF_CHARACTER)
        gTextureTextLevel.render(camX + (clipWIDTH - gTextureTextLevel.getWidth()) / 2, camY + clipHEIGHT + 3);
    gBigFishTexture.render(camX, camY, NULL, 0.0, NULL, flipFish);
}

int ThreatBigFish::getPosX()
{
    return mPosX;
}

int ThreatBigFish::getPosY()
{
    return mPosY;
}

SDL_Rect ThreatBigFish::getLocation()
{
    return locationFish;
}

int ThreatBigFish::getLevel()
{
    return level;
}

SDL_RendererFlip ThreatBigFish::getFlip()
{
    return flipFish;
}

void ThreatBigFish::setNumOfCharacter(int x)
{
    NUM_OF_CHARACTER = x;
}

int ThreatBigFish::getNumOfCharacter()
{
    return NUM_OF_CHARACTER;
}

void ThreatBigFish::setPosX(int x)
{
    mPosX = x;
}

void ThreatBigFish::setPosY(int y)
{
    mPosY = y;
}

void ThreatBigFish::setFlip(SDL_RendererFlip xFlip)
{
    flipFish = xFlip;
}

void ThreatBigFish::characterReset()
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

int ThreatBigFish::getType()
{
    return type;
}