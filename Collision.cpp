#include "Collision.h"
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

bool checkDeadCollision(rectLevel a, rectLevel b)
{
    if (checkCollision(a.location, b.location))
    {
        if (a.Flip != b.Flip)
        {
            return true;
        }
        else
        {
            if (a.Flip == SDL_FLIP_NONE)
            {
                return !(a.location.x > b.location.x);
            }
            else
            {
                return !(a.location.x + a.location.w < b.location.x + b.location.w);
            }
        }
    }
    return false;
}

void checkCharactersCollision()
{
    memset(checkDead, false, sizeof(checkDead));
    setCharacter();

    for (int i = 1; i <= NUM_CHARACTERS; i++)
    {
        for (int j = i + 1; j <= NUM_CHARACTERS; j++)
        {
            if (Character[i].level < Character[j].level)
            {
                if (checkDeadCollision(Character[i], Character[j]))
                {
                    checkDead[i] = true;
                }
            }
        }
    }

    int NUM_CHARACTERS_DEAD = 0;
    for (int i = 0; i < NUM_RED_FISH; i++)
    {
        ++NUM_CHARACTERS_DEAD;
        if (checkDead[NUM_CHARACTERS_DEAD])
        {
            RedFish[i].setPosX(SCREEN_WIDTH);
        }
    }
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        ++NUM_CHARACTERS_DEAD;
        if (checkDead[NUM_CHARACTERS_DEAD])
        {
            BlueFish[i].setPosX(SCREEN_WIDTH);
        }
    }
}