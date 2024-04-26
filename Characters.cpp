#include "Characters.h"
int NUM_RED_FISH = 3;
int NUM_BLUE_FISH = 3;
int NUM_BIG_FISH = 3;

Dot dot;
Threat BlueFish[maxNUM_BLUE_FISH];
ThreatRedFish RedFish[maxNUM_RED_FISH];
ThreatBigFish BigFish[maxNUM_BIG_FISH];

rectLevel Character[1000];
vector<int> validThreat;
int NUM_CHARACTERS = 0;
void setNumThreat()
{
    if (checkYear && YEAR % 10 == 0)
    {
        NUM_MINIONS_CHOOSE = -1;
        checkYear = false;
    }

    if (YEAR >= 90)
    {
        NUM_RED_FISH = 20;
        NUM_BLUE_FISH = 20;
        NUM_BIG_FISH = 20;
        return;
    }
    if (YEAR >= 50)
    {
        NUM_RED_FISH = 14;
        NUM_BLUE_FISH = 20;
        NUM_BIG_FISH = 4;
        return;
    }
    if (YEAR >= 20)
    {
        NUM_RED_FISH = 20;
        NUM_BLUE_FISH = 2;
        NUM_BIG_FISH = 5;
        return;
    }
    if (YEAR >= 10)
    {
        NUM_RED_FISH = 30;
        NUM_BLUE_FISH = 1;
        NUM_BIG_FISH = 1;
        return;
    }
    if (YEAR >= 0)
    {
        NUM_RED_FISH = 8;
        NUM_BLUE_FISH = 4;
        NUM_BIG_FISH = 0;
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

    // move RedFish
    for (int i = 0; i < NUM_BIG_FISH; i++)
    {

        BigFish[i].move();
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
                    dot.setPosX(RedFish[i].getPosX() + RedFish[i].getLocation().w - dot.Minions_WIDTH);
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
                    dot.setPosX(BlueFish[i].getPosX() + BlueFish[i].getLocation().w - dot.Minions_WIDTH);
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

    // render BigFish
    for (int i = 0; i < NUM_BIG_FISH; i++)
    {
        if (BigFish[i].getNumOfCharacter() == NUM_MINIONS_CHOOSE)
        {
            if (BigFish[i].getFlip() == dot.getFlip())
            {
                if (dot.getFlip() == SDL_FLIP_NONE)
                {
                    BigFish[i].setPosX(dot.getPosX() - BigFish[i].getLocation().w);
                    BigFish[i].setPosY(dot.getPosY() - (BigFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
                else if (dot.getFlip() == SDL_FLIP_HORIZONTAL)
                {
                    BigFish[i].setPosX(dot.getPosX() + dot.getLocation().w);
                    BigFish[i].setPosY(dot.getPosY() - (BigFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
            }
            else
            {
                BigFish[i].setFlip(dot.getFlip());
                if (dot.getFlip() == SDL_FLIP_NONE)
                {
                    dot.setPosX(BigFish[i].getPosX() + BigFish[i].getLocation().w - dot.Minions_WIDTH);
                    dot.setPosY(BigFish[i].getPosY() + (BigFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                    if (dot.getPosX() < 0)
                    {
                        // Move back
                        dot.setPosX(0);
                    }
                    else if (dot.getPosX() + dot.Minions_WIDTH > LEVEL_WIDTH)
                    {
                        dot.setPosX(LEVEL_WIDTH - dot.Minions_WIDTH);
                    }

                    BigFish[i].setPosX(dot.getPosX() - BigFish[i].getLocation().w);
                    BigFish[i].setPosY(dot.getPosY() - (BigFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
                else if (dot.getFlip() == SDL_FLIP_HORIZONTAL)
                {
                    dot.setPosX(BigFish[i].getPosX());
                    dot.setPosY(BigFish[i].getPosY() + (BigFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                    if (dot.getPosX() < 0)
                    {
                        // Move back
                        dot.setPosX(0);
                    }
                    else if (dot.getPosX() + dot.Minions_WIDTH > LEVEL_WIDTH)
                    {
                        dot.setPosX(LEVEL_WIDTH - dot.Minions_WIDTH);
                    }

                    BigFish[i].setPosX(dot.getPosX() + dot.getLocation().w);
                    BigFish[i].setPosY(dot.getPosY() - (BigFish[i].getLocation().h - dot.Minions_HEIGHT) / 2);
                }
            }
        }
        BigFish[i].render(BigFish[i].getPosX(), BigFish[i].getPosY());
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
    Character[0] = {dot.getLocation(), dot.getLevel(), dot.getFlip(), dot.getType()};
    NUM_CHARACTERS = 0;
    for (int i = 0; i < NUM_RED_FISH; i++)
    {
        Character[++NUM_CHARACTERS] = {RedFish[i].getLocation(), RedFish[i].getLevel(), RedFish[i].getFlip(), RedFish[i].getType()};
        RedFish[i].setNumOfCharacter(NUM_CHARACTERS);
        if (checkValidThreat(Character[NUM_CHARACTERS]))
        {
            validThreat.push_back(NUM_CHARACTERS);
        }
    }
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        Character[++NUM_CHARACTERS] = {BlueFish[i].getLocation(), BlueFish[i].getLevel(), BlueFish[i].getFlip(), BlueFish[i].getType()};
        BlueFish[i].setNumOfCharacter(NUM_CHARACTERS);
        if (checkValidThreat(Character[NUM_CHARACTERS]))
        {
            validThreat.push_back(NUM_CHARACTERS);
        }
    }
    for (int i = 0; i < NUM_BIG_FISH; i++)
    {
        Character[++NUM_CHARACTERS] = {BigFish[i].getLocation(), BigFish[i].getLevel(), BigFish[i].getFlip(), BigFish[i].getType()};
        BigFish[i].setNumOfCharacter(NUM_CHARACTERS);
        if (checkValidThreat(Character[NUM_CHARACTERS]))
        {
            validThreat.push_back(NUM_CHARACTERS);
        }
    }
}