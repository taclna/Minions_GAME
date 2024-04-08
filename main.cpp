#include "ALL.h"
#include "Windows.h"
#include "Texture.h"
#include "Dot.h"
#include "Threat.h"
#include "ThreatRedFish.h"

int maxNUM_RED_FISH = 100;
int maxNUM_BLUE_FISH = 100;
int NUM_RED_FISH = 1;
int NUM_BLUE_FISH = 1;

void setNumThreat()
{
    if (SDL_GetTicks() >= Uint32(10000))
    {
        NUM_RED_FISH = 10;
        NUM_BLUE_FISH = 5;
        return;
    }
    if (SDL_GetTicks() >= 0)
    {
        NUM_RED_FISH = 4;
        NUM_BLUE_FISH = 2;
        return;
    }
}
void untilQuit()
{
    bool quit = false;

    // Event handler
    SDL_Event e;

    Dot dot;
    Threat BlueFish[maxNUM_BLUE_FISH];
    ThreatRedFish RedFish[maxNUM_RED_FISH];

    // While application is running
    while (!quit)
    {
        // Handle events on queue
        setNumThreat();
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }

            // Handle input for the dot
            dot.handleEvent(e);
        }

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

        // Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        // Render background
        gBGTexture.render(0, 0);

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

        // Update screen
        SDL_RenderPresent(gRenderer);
    }
}

int main(int argc, char *args[])
{
    // Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        // Load media
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            setMinionsAnimation();
            setRedFishAnimation();

            untilQuit();
            // Main loop flag
        }
    }

    // Free resources and close SDL
    close();

    return 0;
}
