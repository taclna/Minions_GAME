#include "ALL.h"
#include "Windows.h"
#include "Texture.h"
#include "Dot.h"
#include "Threat.h"
#include "ThreatRedFish.h"
#include "Characters.h"
#include "Collision.h"

void untilQuit()
{
    bool quit = false;

    // Event handler
    SDL_Event e;

    // While application is running
    while (!quit)
    {
        setNumThreat();

        // Handle events on queue
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
        charactersMove();
        checkCharactersCollision();

        // Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        // Render background
        gBGTexture.render(0, 0);

        charactersRender();

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
