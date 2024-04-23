#include "ALL.h"
#include "Windows.h"
#include "Texture.h"
#include "Dot.h"
#include "Threat.h"
#include "ThreatRedFish.h"
#include "Characters.h"
#include "Collision.h"
#include "Skill.h"
#include "GameOver.h"
#include "Menu.h"

void gamePlay()
{
    bool quit = false;

    // Event handler
    SDL_Event e;

    // While application is running
    while (!quit)
    {
        setLevel();
        setNumThreat();
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }

            handleSkillEvent(e);
            // Handle input for the dot
            dot.handleEvent(e);
        }
        charactersMove();

        // Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        // Render background
        gBGTexture.render(0, 0);

        charactersRender();

        renderTimeLevel();

        // Update screen
        SDL_RenderPresent(gRenderer);

        setCharacter();

        checkCharactersCollision();

        if (checkGameOver())
        {
            quit = true;
        }
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
            gFontTextLevel = TTF_OpenFont("Data/Font/Nihonium113.ttf", 13);
            setMinionsAnimation();
            setRedFishAnimation();

            int SCREEN_NOW = checkMouseMenu();
            while (SCREEN_NOW != NUM_EXIT_MENU)
            {
                if (SCREEN_NOW == NUM_PLAY_MENU)
                {
                    reset();
                    gamePlay();
                    break;
                }
                else
                {
                    SCREEN_NOW = showHowToPlay();
                }
            }
            // Main loop flag
        }
    }

    // Free resources and close SDL
    close();

    return 0;
}
