#include "Reset.h"

void resetCharacter()
{
    dot.characterReset();
    for (int i = 0; i < NUM_RED_FISH; i++)
    {
        RedFish[i].characterReset();
    }
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        BlueFish[i].characterReset();
    }
}

void reset()
{
    resetCharacter();
}