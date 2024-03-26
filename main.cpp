/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

// Using SDL, SDL_image, standard IO, vectors, and strings
#include "ALL.h"
#include "Windows.h"
#include "Texture.h"
#include "Dot.h"
// Texture wrapper class

// The dot that will move around on the screen

// Scene textures

// #if defined(SDL_TTF_MAJOR_VERSION)
// bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
// {
//     // Get rid of preexisting texture
//     free();

//     // Render text surface
//     SDL_Surface *textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
//     if (textSurface != NULL)
//     {
//         // Create texture from surface pixels
//         mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
//         if (mTexture == NULL)
//         {
//             printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
//         }
//         else
//         {
//             // Get image dimensions
//             mWidth = textSurface->w;
//             mHeight = textSurface->h;
//         }

//         // Get rid of old surface
//         SDL_FreeSurface(textSurface);
//     }
//     else
//     {
//         printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
//     }

//     // Return success
//     return mTexture != NULL;
// }
// #endif

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
            // Main loop flag
            bool quit = false;

            // Event handler
            SDL_Event e;

            // The dot that will be moving around on the screen
            Dot dot;

            // The camera area
            SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

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
                    dot.handleEvent(e);
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
                dot.render(camera.x, camera.y);

                // Update screen
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    // Free resources and close SDL
    close();

    return 0;
}
