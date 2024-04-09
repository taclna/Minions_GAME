#include "Collision.h"
rectLevel Character[1000];
bool checkDead[1000];

bool checkCollision(SDL_Rect a, SDL_Rect b)
{
    // The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    // Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    // Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    // If any of the sides from A are outside of B
    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    // If none of the sides from A are outside B
    return true;
}

void checkCharactersCollision()
{
    memset(checkDead, false, sizeof(checkDead));
    Character[0] = {dot.getLocation(), dot.getLevel()};
    int NUM_CHARACTERS = 0;

    for (int i = 0; i < NUM_RED_FISH; i++)
    {
        Character[++NUM_CHARACTERS] = {RedFish[i].getLocation(), RedFish[i].getLevel()};
    }
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        Character[++NUM_CHARACTERS] = {BlueFish[i].getLocation(), BlueFish[i].getLevel()};
    }

    for (int i = 1; i <= NUM_CHARACTERS; i++)
    {
        for (int j = i + 1; j <= NUM_CHARACTERS; j++)
        {
            if (Character[i].level < Character[j].level)
            {
                if (checkCollision(Character[i].location, Character[j].location))
                {
                    checkDead[i] = true;
                }
            }
        }
    }

    NUM_CHARACTERS = 0;
    for (int i = 0; i < NUM_RED_FISH; i++)
    {
        Character[++NUM_CHARACTERS] = {RedFish[i].getLocation(), RedFish[i].getLevel()};
        if (checkDead[NUM_CHARACTERS])
        {
            RedFish[i].setPosX(SCREEN_WIDTH);
        }
    }
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        Character[++NUM_CHARACTERS] = {BlueFish[i].getLocation(), BlueFish[i].getLevel()};
        if (checkDead[NUM_CHARACTERS])
        {
            BlueFish[i].setPosX(SCREEN_WIDTH);
        }
    }
}