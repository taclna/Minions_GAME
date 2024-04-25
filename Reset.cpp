#include "Reset.h"

void resetCharacter()
{
    dot.characterReset();
    for (int i = 0; i < maxNUM_RED_FISH; i++)
    {
        RedFish[i].characterReset();
    }
    for (int i = 0; i < maxNUM_BLUE_FISH; i++)
    {
        BlueFish[i].characterReset();
    }
    for (int i = 0; i < maxNUM_BIG_FISH; i++)
    {
        BigFish[i].characterReset();
    }
}

void reset()
{
    timeStartedGame = SDL_GetTicks();
    nowTimeCoolDownSkill = SDL_GetTicks();
    NUM_MINIONS_CHOOSE = -1;
    levelMinions = 0;
    YEAR = 0;
    oldYEAR = YEAR;

    resetCharacter();
}