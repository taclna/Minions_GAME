#include "ThreatRedFish.h"
SDL_Rect gRedFishClips[2];
const int clipWIDTH = 72;
const int clipHEIGHT = 68;
void setRedFishAnimation()
{
    gRedFishClips[0].x = 0;
    gRedFishClips[0].y = 0;
    gRedFishClips[0].w = clipWIDTH;
    gRedFishClips[0].h = clipHEIGHT;

    gRedFishClips[1].x = 72;
    gRedFishClips[1].y = 0;
    gRedFishClips[1].w = clipWIDTH;
    gRedFishClips[1].h = clipHEIGHT;
}
ThreatRedFish::ThreatRedFish()
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
    mVelX = 2;
    mVelY = 1;
    cnt = 0;
    frame = 0;

    type = 5;

    textLevel = "LEVEL.  5";
}
void ThreatRedFish::move()
{
    ++frame;
    if (frame / 16 >= 2)
    {
        frame = 0;
    }

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

void ThreatRedFish::render(int camX, int camY, SDL_Rect *clip, SDL_RendererFlip flip)
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
        cout << "khong load duoc redfish gTextureTextLevel" << endl;
    }

    if (timeStartedGame != 0 && NUM_MINIONS_CHOOSE != NUM_OF_CHARACTER)
        gTextureTextLevel.render(camX + (clipWIDTH - gTextureTextLevel.getWidth()) / 2, camY + clipHEIGHT + 3);
    SDL_Rect *currentClip = &gRedFishClips[frame / 16];
    gRedFishTexture.render(camX, camY, currentClip, 0.0, NULL, flipFish);
    Fish_HETGHT = int(frame / 16) == 1 ? 51 : 68;
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
    return locationFish;
}

int ThreatRedFish::getLevel()
{
    return level;
}

SDL_RendererFlip ThreatRedFish::getFlip()
{
    return flipFish;
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
    flipFish = xFlip;
}

void ThreatRedFish::characterReset()
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

int ThreatRedFish::getType()
{
    return type;
}