#include "Characters.h"
int NUM_RED_FISH = 6;
int NUM_BLUE_FISH = 2;
Dot dot;
Threat BlueFish[maxNUM_BLUE_FISH];
ThreatRedFish RedFish[maxNUM_RED_FISH];
rectLevel Character[1000];
int NUM_CHARACTERS = 0;
void setNumThreat()
{
    if (SDL_GetTicks() >= 10000)
    {
        NUM_RED_FISH = 10;
        NUM_BLUE_FISH = 5;
        levelMinions = 100;
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

void setCharacter()
{
    Character[0] = {dot.getLocation(), dot.getLevel(), dot.getFlip()};
    NUM_CHARACTERS = 0;
    for (int i = 0; i < NUM_RED_FISH; i++)
    {
        Character[++NUM_CHARACTERS] = {RedFish[i].getLocation(), RedFish[i].getLevel(), RedFish[i].getFlip()};
        RedFish[i].setNumOfCharacter(NUM_CHARACTERS);
    }
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        Character[++NUM_CHARACTERS] = {BlueFish[i].getLocation(), BlueFish[i].getLevel(), BlueFish[i].getFlip()};
        BlueFish[i].setNumOfCharacter(NUM_CHARACTERS);
    }
}