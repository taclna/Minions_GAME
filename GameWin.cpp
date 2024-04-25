#include "GameWin.h"

string textPlayAgainGW = "PLAY AGAIN";
string textMenuGW = "MENU";
string textExitGW = "EXIT";

LTexture gGameWinBTexture;
LTexture gPlayAgainTextTexture;
LTexture gMenuTextTexture;
LTexture gExitTextTexture;

TTF_Font *gFontGameWin = NULL;

SDL_Color colorPlayAgainGW = colorWhite;
SDL_Color colorMenuGW = colorWhite;
SDL_Color colorExitGW = colorWhite;

void setGameWin()
{
    if (!gGameWinBTexture.loadFromFile("Data/PrimitiveEra/backGameWintext.png"))
    {
        cout << "khong load duoc back game win";
    }
    gFontGameWin = TTF_OpenFont("Data/Font/Nihonium113.ttf", 40);
    if (!gPlayAgainTextTexture.loadFromRenderedText(gFontGameWin, textPlayAgainGW, colorPlayAgainGW))
    {
        cout << "khong load duoc gPlayAgainTextTexture";
    }
    if (!gMenuTextTexture.loadFromRenderedText(gFontGameWin, textMenuGW, colorMenuGW))
    {
        cout << "khong load duoc gPlayAgainTextTexture";
    }
    if (!gExitTextTexture.loadFromRenderedText(gFontGameWin, textExitGW, colorExitGW))
    {
        cout << "khong load duoc gPlayAgainTextTexture";
    }
}

void freeGameWin()
{
    gGameWinBTexture.free();
    gPlayAgainTextTexture.free();
    gMenuTextTexture.free();
    gExitTextTexture.free();
    gFontGameWin = NULL;
}

void renderScreenGameWin()
{
    setGameWin();
    // Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);

    gGameWinBTexture.render(0, 0);
    gPlayAgainTextTexture.render(170, 170);
    gMenuTextTexture.render(gPlayAgainTextTexture.getPosX(), gPlayAgainTextTexture.getPosY() + gPlayAgainTextTexture.getHeight());
    gExitTextTexture.render(gMenuTextTexture.getPosX(), gMenuTextTexture.getPosY() + gMenuTextTexture.getHeight());

    // Update screen
    SDL_RenderPresent(gRenderer);
}

int checkMouseGameWin()
{
    renderScreenGameWin();

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
                colorPlayAgainGW = colorWhite;
                colorMenuGW = colorWhite;
                colorExitGW = colorWhite;

                if (checkIn(mousePosX, mousePosY, gPlayAgainTextTexture))
                {
                    colorPlayAgainGW = colorYellow;
                }
                if (checkIn(mousePosX, mousePosY, gMenuTextTexture))
                {
                    colorMenuGW = colorYellow;
                }
                if (checkIn(mousePosX, mousePosY, gExitTextTexture))
                {
                    colorExitGW = colorYellow;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                mousePosX = e.motion.x, mousePosY = e.motion.y;
                if (checkIn(mousePosX, mousePosY, gPlayAgainTextTexture))
                {
                    return NUM_PLAY_MENU;
                }
                if (checkIn(mousePosX, mousePosY, gMenuTextTexture))
                {
                    return NUM_COME_TO_MENU;
                }
                if (checkIn(mousePosX, mousePosY, gExitTextTexture))
                {
                    return NUM_EXIT_MENU;
                }
                break;
            }
        }

        renderScreenGameWin();
    }

    return 1903;
}