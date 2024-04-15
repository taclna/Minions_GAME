
#include "Windows.h"
SDL_Window *gWindow = NULL;

// The window renderer
SDL_Renderer *gRenderer = NULL;

bool init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        // Create window
        gWindow = SDL_CreateWindow("Minions", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }

                // Initialize SDL_ttf
                if (TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    // Loading success flag
    bool success = true;

    // Load dot texture
    if (!gDotTexture.loadFromFile("Data/PrimitiveEra/minions.png"))
    {
        printf("Failed to load dot texture!\n");
        success = false;
    }
    // Load Bluefish texture
    if (!gBlueFishTexture.loadFromFile("Data/PrimitiveEra/blueFish.png"))
    {
        printf("Failed to load blue fish texture!\n");
        success = false;
    }
    // load Redfish texture
    if (!gRedFishTexture.loadFromFile("Data/PrimitiveEra/redFish.png"))
    {
        printf("Failed to load blue fish texture!\n");
        success = false;
    }
    // Load background texture
    if (!gBGTexture.loadFromFile("Data/PrimitiveEra/backgroud1080x756.png"))
    {
        printf("Failed to load background texture!\n");
        success = false;
    }

    if (!gBlackBTexture.loadFromFile("Data/PrimitiveEra/blackBack.png"))
    {
        cout << "Failed to load black background texture!\n";
        success = false;
    }

    if (!gGreyBTexture.loadFromFile("Data/PrimitiveEra/greyBack.png"))
    {
        cout << "Failed to load grey background texture!\n";
        success = false;
    }

    if (!gMenuBackTexture.loadFromFile("Data/PrimitiveEra/menu.png"))
    {
        cout << "Failed to load menu background texture!\n";
        success = false;
    }

    return success;
}

void close()
{
    // Free loaded images
    gDotTexture.free();
    gBGTexture.free();
    gBlueFishTexture.free();
    gRedFishTexture.free();
    gBlackBTexture.free();
    gGreyBTexture.free();
    gMenuBackTexture.free();

    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    gFontTextLevel = NULL;

    // Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}