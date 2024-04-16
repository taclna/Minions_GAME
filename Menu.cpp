#include "Menu.h"

string textPlay = "PLAY";
string textHowToPlay = "HOW TO PLAY";
string textExitMenu = "EXIT";

TTF_Font *gFontMenu = NULL;

LTexture gTextPlayTexture;
LTexture gTextHowToPlayTexture;
LTexture gTextExitTextureMenu;

SDL_Color colorMenuTextPlay = colorWhite;
SDL_Color colorMenuTextHTP = colorWhite;
SDL_Color colorMenuTextExit = colorWhite;

SDL_Rect gHowToPlayClips[3];
int NUM_PICTURE_HTP = 3;
int NOW_PICTURE = 0;
void setHowToPlayAnimation()
{
    gHowToPlayClips[0].x = 0;
    gHowToPlayClips[0].y = 0;
    gHowToPlayClips[0].w = 1080;
    gHowToPlayClips[0].h = 756;

    gHowToPlayClips[1].x = 1080;
    gHowToPlayClips[1].y = 0;
    gHowToPlayClips[1].w = 1080;
    gHowToPlayClips[1].h = 756;

    gHowToPlayClips[2].x = 2160;
    gHowToPlayClips[2].y = 0;
    gHowToPlayClips[2].w = 1080;
    gHowToPlayClips[2].h = 756;
}

void freeTT()
{
    gFontMenu = NULL;

    gTextPlayTexture.free();
    gTextHowToPlayTexture.free();
    gTextExitTextureMenu.free();
}
void setText()
{
    gFontMenu = TTF_OpenFont("Data/Font/nihonium113.regular.ttf", 60);

    gTextPlayTexture.loadFromRenderedText(gFontMenu, textPlay, colorMenuTextPlay);
    gTextHowToPlayTexture.loadFromRenderedText(gFontMenu, textHowToPlay, colorMenuTextHTP);
    gTextExitTextureMenu.loadFromRenderedText(gFontMenu, textExitMenu, colorMenuTextExit);
}
void renderScreenMenu()
{
    setText();
    // Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);

    charactersMove();

    gMenuBackTexture.render(0, 0);
    gTextPlayTexture.render(150, 350);
    gTextHowToPlayTexture.render(gTextPlayTexture.getPosX(), gTextPlayTexture.getPosY() + gTextHowToPlayTexture.getHeight());
    gTextExitTextureMenu.render(gTextHowToPlayTexture.getPosX(), gTextHowToPlayTexture.getPosY() + gTextHowToPlayTexture.getHeight());
    charactersRender();
    // Update screen
    SDL_RenderPresent(gRenderer);
}

void renderScreenHowToPlay()
{
    SDL_Rect *currentClip = &gHowToPlayClips[NOW_PICTURE];
    // Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);

    gHowToPlayTexture.render(0, 0, currentClip);
    // Update screen
    SDL_RenderPresent(gRenderer);
}
int showHowToPlay()
{
    setHowToPlayAnimation();
    bool quit = false;

    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            int mousePosX, mousePosY;
            switch (e.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                NOW_PICTURE++;
                if (NOW_PICTURE > 2)
                    return NUM_PLAY_MENU;
            }
        }
        renderScreenHowToPlay();
    }
    return 1903;
}
int checkMouseMenu()
{
    bool quit = false;

    // Event handler
    SDL_Event e;

    // While application is running
    while (!quit)
    {
        int mousePosX, mousePosY;
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            switch (e.type)
            {
            // User requests quit
            case SDL_QUIT:
                return NUM_EXIT_MENU;
                break;

            case SDL_MOUSEMOTION:
                mousePosX = e.motion.x, mousePosY = e.motion.y;
                colorMenuTextPlay = colorWhite;
                colorMenuTextHTP = colorWhite;
                colorMenuTextExit = colorWhite;

                if (checkIn(mousePosX, mousePosY, gTextPlayTexture))
                {
                    colorMenuTextPlay = colorYellow;
                }
                if (checkIn(mousePosX, mousePosY, gTextHowToPlayTexture))
                {
                    colorMenuTextHTP = colorYellow;
                }
                if (checkIn(mousePosX, mousePosY, gTextExitTextureMenu))
                {
                    colorMenuTextExit = colorYellow;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                mousePosX = e.motion.x, mousePosY = e.motion.y;
                if (checkIn(mousePosX, mousePosY, gTextPlayTexture))
                {
                    return NUM_PLAY_MENU;
                }
                if (checkIn(mousePosX, mousePosY, gTextHowToPlayTexture))
                {
                    return NUM_HOW_TO_PLAY_MENU;
                }
                if (checkIn(mousePosX, mousePosY, gTextExitTextureMenu))
                {
                    return NUM_EXIT_MENU;
                }
                break;
            }

            dot.handleEvent(e);
        }

        renderScreenMenu();
    }

    return 1903;
}

void showMenu()
{

    reset();
}