/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

// Using SDL, SDL_image, standard IO, vectors, and strings
#include "ALL.h"
#include "Windows.h"
#include "Texture.h"
#include "Dot.h"

SDL_Rect gMinionsClips[4];
SDL_RendererFlip flipMinion = SDL_FLIP_NONE;
void setMinionsAnimation()
{
    gMinionsClips[0].x = 0;
    gMinionsClips[0].y = 0;
    gMinionsClips[0].w = 32;
    gMinionsClips[0].h = 32;

    gMinionsClips[1].x = 32;
    gMinionsClips[1].y = 0;
    gMinionsClips[1].w = 32;
    gMinionsClips[1].h = 32;

    gMinionsClips[2].x = 64;
    gMinionsClips[2].y = 0;
    gMinionsClips[2].w = 32;
    gMinionsClips[2].h = 32;

    gMinionsClips[3].x = 96;
    gMinionsClips[3].y = 0;
    gMinionsClips[3].w = 32;
    gMinionsClips[3].h = 32;
}
void untilQuit()
{
    bool quit = false;

    // Event handler
    SDL_Event e;

    // The dot that will be moving around on the screen
    Dot dot;

    // The camera area
    SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    int frame = 0;
    // While application is running
    while (!quit)
    {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }

            // Handle input for the dot
            dot.handleEvent(e, flipMinion);
        }

        // Move the dot
        dot.move();

        // Center the camera over the dot
        camera.x = (dot.getPosX() + Dot::DOT_WIDTH / 2) - SCREEN_WIDTH / 2;
        camera.y = (dot.getPosY() + Dot::DOT_HEIGHT / 2) - SCREEN_HEIGHT / 2;

        // Keep the camera in bounds
        if (camera.x < 0)
        {
            camera.x = 0;
        }
        if (camera.y < 0)
        {
            camera.y = 0;
        }
        if (camera.x > LEVEL_WIDTH - camera.w)
        {
            camera.x = LEVEL_WIDTH - camera.w;
        }
        if (camera.y > LEVEL_HEIGHT - camera.h)
        {
            camera.y = LEVEL_HEIGHT - camera.h;
        }

        // Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        // Render background
        gBGTexture.render(0, 0, &camera);

        // Render objects
        SDL_Rect *currentClip = &gMinionsClips[frame / 4];
        dot.render(camera.x, camera.y, currentClip, flipMinion);
        ++frame;
        if (frame / 4 >= 4)
        {
            frame = 0;
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
            untilQuit();
            // Main loop flag
        }
    }

    // Free resources and close SDL
    close();

    return 0;
}
