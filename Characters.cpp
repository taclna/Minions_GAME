#include "Characters.h"
int NUM_RED_FISH = 6;
int NUM_BLUE_FISH = 2;
Dot dot;
Threat BlueFish[maxNUM_BLUE_FISH];
ThreatRedFish RedFish[maxNUM_RED_FISH];
rectLevel Character[1000];
vector<int> validThreat;
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
        if (RedFish[i].getNumOfCharacter() == NUM_MINIONS_CHOOSE)
        {
            if (RedFish[i].getFlip() == dot.getFlip())
            {
                if (dot.getFlip() == SDL_FLIP_NONE)
                {
                    RedFish[i].setPosX(dot.getPosX() - RedFish[i].getLocation().w);
                    RedFish[i].setPosY(dot.getPosY() - (RedFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
                else if (dot.getFlip() == SDL_FLIP_HORIZONTAL)
                {
                    RedFish[i].setPosX(dot.getPosX() + dot.getLocation().w);
                    RedFish[i].setPosY(dot.getPosY() - (RedFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
            }
            else
            {
                RedFish[i].setFlip(dot.getFlip());
                if (dot.getFlip() == SDL_FLIP_NONE)
                {
                    dot.setPosX(RedFish[i].getPosX() + RedFish[i].getLocation().h - dot.Minions_WIDTH);
                    dot.setPosY(RedFish[i].getPosY() + (RedFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                    if (dot.getPosX() < 0)
                    {
                        // Move back
                        dot.setPosX(0);
                    }
                    else if (dot.getPosX() + dot.Minions_WIDTH > LEVEL_WIDTH)
                    {
                        dot.setPosX(LEVEL_WIDTH - dot.Minions_WIDTH);
                    }
                    // RedFish[i].setPosX(dot.getPosX() - RedFish[i].getLocation().w);
                    // RedFish[i].setPosY(dot.getPosY() - (RedFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
                else if (dot.getFlip() == SDL_FLIP_HORIZONTAL)
                {
                    dot.setPosX(RedFish[i].getPosX());
                    dot.setPosY(RedFish[i].getPosY() + (RedFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                    if (dot.getPosX() < 0)
                    {
                        // Move back
                        dot.setPosX(0);
                    }
                    else if (dot.getPosX() + dot.Minions_WIDTH > LEVEL_WIDTH)
                    {
                        dot.setPosX(LEVEL_WIDTH - dot.Minions_WIDTH);
                    }
                    // RedFish[i].setPosX(dot.getPosX() + dot.getLocation().w);
                    // RedFish[i].setPosY(dot.getPosY() - (RedFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
            }
        }
        RedFish[i].render(RedFish[i].getPosX(), RedFish[i].getPosY());
    }

    // Render BlueFish
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        if (BlueFish[i].getNumOfCharacter() == NUM_MINIONS_CHOOSE)
        {
            if (BlueFish[i].getFlip() == dot.getFlip())
            {
                if (dot.getFlip() == SDL_FLIP_NONE)
                {
                    BlueFish[i].setPosX(dot.getPosX() - BlueFish[i].getLocation().w);
                    BlueFish[i].setPosY(dot.getPosY() - (BlueFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
                else if (dot.getFlip() == SDL_FLIP_HORIZONTAL)
                {
                    BlueFish[i].setPosX(dot.getPosX() + dot.getLocation().w);
                    BlueFish[i].setPosY(dot.getPosY() - (BlueFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
            }
            else
            {
                BlueFish[i].setFlip(dot.getFlip());
                if (dot.getFlip() == SDL_FLIP_NONE)
                {
                    dot.setPosX(BlueFish[i].getPosX() + BlueFish[i].getLocation().h - dot.Minions_WIDTH);
                    dot.setPosY(BlueFish[i].getPosY() + (BlueFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                    if (dot.getPosX() < 0)
                    {
                        // Move back
                        dot.setPosX(0);
                    }
                    else if (dot.getPosX() + dot.Minions_WIDTH > LEVEL_WIDTH)
                    {
                        dot.setPosX(LEVEL_WIDTH - dot.Minions_WIDTH);
                    }

                    BlueFish[i].setPosX(dot.getPosX() - BlueFish[i].getLocation().w);
                    BlueFish[i].setPosY(dot.getPosY() - (BlueFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
                else if (dot.getFlip() == SDL_FLIP_HORIZONTAL)
                {
                    dot.setPosX(BlueFish[i].getPosX());
                    dot.setPosY(BlueFish[i].getPosY() + (BlueFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                    if (dot.getPosX() < 0)
                    {
                        // Move back
                        dot.setPosX(0);
                    }
                    else if (dot.getPosX() + dot.Minions_WIDTH > LEVEL_WIDTH)
                    {
                        dot.setPosX(LEVEL_WIDTH - dot.Minions_WIDTH);
                    }

                    BlueFish[i].setPosX(dot.getPosX() + dot.getLocation().w);
                    BlueFish[i].setPosY(dot.getPosY() - (BlueFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
            }
        }
        BlueFish[i].render(BlueFish[i].getPosX(), BlueFish[i].getPosY());
    }
}

bool checkValidThreat(rectLevel a)
{
    if (levelMinions < a.level)
        return false;
    if (a.Flip == SDL_FLIP_NONE)
    {
        return a.location.x + a.location.w + dot.Minions_WIDTH < SCREEN_WIDTH;
    }
    else
    {
        return a.location.x - dot.Minions_WIDTH > 0;
    }
}

void setCharacter()
{
    validThreat.clear();
    Character[0] = {dot.getLocation(), dot.getLevel(), dot.getFlip()};
    NUM_CHARACTERS = 0;
    for (int i = 0; i < NUM_RED_FISH; i++)
    {
        Character[++NUM_CHARACTERS] = {RedFish[i].getLocation(), RedFish[i].getLevel(), RedFish[i].getFlip()};
        RedFish[i].setNumOfCharacter(NUM_CHARACTERS);
        if (checkValidThreat(Character[NUM_CHARACTERS]))
        {
            validThreat.push_back(NUM_CHARACTERS);
        }
    }
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        Character[++NUM_CHARACTERS] = {BlueFish[i].getLocation(), BlueFish[i].getLevel(), BlueFish[i].getFlip()};
        BlueFish[i].setNumOfCharacter(NUM_CHARACTERS);
        if (checkValidThreat(Character[NUM_CHARACTERS]))
        {
            validThreat.push_back(NUM_CHARACTERS);
        }
    }
}