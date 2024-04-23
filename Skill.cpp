#include "Skill.h"
bool quit = false;

void renderSkillScreen(int NUM_OF_CHARACTER)
{
    gBlackBTexture.setAlpha(200);
    // Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);

    // Render background
    gBGTexture.render(0, 0);

    // Render RedFish
    for (int i = 0; i < NUM_RED_FISH; i++)
    {
        if (RedFish[i].getNumOfCharacter() != NUM_OF_CHARACTER)
        {
            RedFish[i].render(RedFish[i].getPosX(), RedFish[i].getPosY());
        }
    }

    // Render BlueFish
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        if (BlueFish[i].getNumOfCharacter() != NUM_OF_CHARACTER)
        {
            BlueFish[i].render(BlueFish[i].getPosX(), BlueFish[i].getPosY());
        }
    }

    gBlackBTexture.render(0, 0);
    dot.render(dot.getPosX(), dot.getPosY());
    // Render RedFish
    for (int i = 0; i < NUM_RED_FISH; i++)
    {
        if (RedFish[i].getNumOfCharacter() == NUM_OF_CHARACTER)
        {
            RedFish[i].render(RedFish[i].getPosX(), RedFish[i].getPosY());
        }
    }

    // Render BlueFish
    for (int i = 0; i < NUM_BLUE_FISH; i++)
    {
        if (BlueFish[i].getNumOfCharacter() == NUM_OF_CHARACTER)
        {
            BlueFish[i].render(BlueFish[i].getPosX(), BlueFish[i].getPosY());
        }
    }

    // Update screen
    SDL_RenderPresent(gRenderer);
}

void chooseThreat()
{
    SDL_Event e;
    int NUM_OF_CHARACTER = 0;
    bool quitChooseThreat = false;
    while (!quitChooseThreat)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_KEYDOWN)
            {
                // Adjust the velocity
                switch (e.key.keysym.sym)
                {
                case SDLK_TAB:
                    ++NUM_OF_CHARACTER;
                    break;
                case SDLK_RETURN:
                    NUM_MINIONS_CHOOSE = validThreat[NUM_OF_CHARACTER];
                    MinionsCometoThreat();
                    quitChooseThreat = true;
                    quit = true;
                    timeChooseThreat = SDL_GetTicks();
                    break;
                case SDLK_q:
                    quitChooseThreat = true;
                    quit = true;
                    break;
                }
            }
        }
        if (validThreat.size() == 0)
        {
            quit = true;
            break;
        }
        NUM_OF_CHARACTER %= validThreat.size();
        renderSkillScreen(validThreat[NUM_OF_CHARACTER]);
    }
}

void MinionsCometoThreat()
{
    dot.setFlip(Character[NUM_MINIONS_CHOOSE].Flip);
    if (dot.getFlip() == SDL_FLIP_NONE)
    {
        dot.setPosX(Character[NUM_MINIONS_CHOOSE].location.x + Character[NUM_MINIONS_CHOOSE].location.w);
        dot.setPosY(Character[NUM_MINIONS_CHOOSE].location.y + (Character[NUM_MINIONS_CHOOSE].location.h - dot.Minions_HEIGHT) / 2);
    }
    else
    {
        dot.setPosX(Character[NUM_MINIONS_CHOOSE].location.x - dot.Minions_WIDTH);
        dot.setPosY(Character[NUM_MINIONS_CHOOSE].location.y + (Character[NUM_MINIONS_CHOOSE].location.h - dot.Minions_HEIGHT) / 2);
    }
}

void handleSkillEvent(SDL_Event &e)
{
    // If a key was pressed
    if (e.type == SDL_KEYDOWN)
    {
        // Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_TAB:
            quit = false;
            while (!quit)
            {
                chooseThreat();
            }
            break;
        case SDLK_q:
            NUM_MINIONS_CHOOSE = -1;
        }
    }
}
