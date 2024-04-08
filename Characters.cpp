#include "Characters.h"
int NUM_RED_FISH = 4;
int NUM_BLUE_FISH = 2;
Dot dot;
Threat BlueFish[maxNUM_BLUE_FISH];
ThreatRedFish RedFish[maxNUM_RED_FISH];
void setNumThreat()
{
    if (SDL_GetTicks() >= 10000)
    {
        NUM_RED_FISH = 10;
        NUM_BLUE_FISH = 5;
        return;
    }
}

void charactersMove()
{
    // Move the dot
    dot.move();

    // move BlueFish
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        BlueFish[i].move();
    }

    // move RedFish
    for (int i = 0; i < NUM_RED_FISH; i++)
    {
        RedFish[i].move();
    }
}

void charactersRender()
{
    // Render minions
    dot.render(dot.getPosX(), dot.getPosY());

    // Render RedFish
    for (int i = 0; i < NUM_RED_FISH; i++)
    {
        RedFish[i].render(RedFish[i].getPosX(), RedFish[i].getPosY());
    }

    // Render BlueFish
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        BlueFish[i].render(BlueFish[i].getPosX(), BlueFish[i].getPosY());
    }
}