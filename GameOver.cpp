#include "GameOver.h"

string textGameOver = "GAME OVER";
string textPlayAgain = "PLAY AGAIN";
string textExit = "EXIT";

TTF_Font *gFontTextGameOver = NULL;
TTF_Font *gFontTextMenu = NULL;

SDL_Color colorTextPlayAgain = colorWhite;
SDL_Color colorTextExit = colorWhite;

LTexture gTextureTextGameOver;
LTexture gTextureTextPlayAgain;
LTexture gTextureTextExit;

void renderScreenGameOver()
{
    // Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);

    gFontTextGameOver = TTF_OpenFont("Data/Font/Nihonium113.ttf", 150);
    gFontTextMenu = TTF_OpenFont("Data/Font/Nihonium113.ttf", 40);

    gTextureTextGameOver.loadFromRenderedText(gFontTextGameOver, textGameOver, colorRed);
    gTextureTextPlayAgain.loadFromRenderedText(gFontTextMenu, textPlayAgain, colorTextPlayAgain);
    gTextureTextExit.loadFromRenderedText(gFontTextMenu, textExit, colorTextExit);

    gBlackBTexture.setAlpha(200);

    gBGTexture.render(0, 0);

    charactersRender();

    gBlackBTexture.render(0, 0);

    gTextureTextGameOver.render((SCREEN_WIDTH - gTextureTextGameOver.getWidth()) / 2, (SCREEN_HEIGHT - gTextureTextGameOver.getHeight()) / 2 - 30);
    gTextureTextPlayAgain.render(gTextureTextGameOver.getPosX(), gTextureTextGameOver.getPosY() + gTextureTextGameOver.getHeight());
    gTextureTextExit.render(gTextureTextGameOver.getPosX(), gTextureTextGameOver.getPosY() + gTextureTextGameOver.getHeight() + gTextureTextPlayAgain.getHeight());

    SDL_RenderPresent(gRenderer);

    // free()
    gFontTextGameOver = NULL;
    gFontTextMenu = NULL;
}

bool checkIn(int &mPosX, int &mPosY, LTexture &gTextureCheckIn)
{
    return (mPosX >= gTextureCheckIn.getPosX()) && (mPosX <= gTextureCheckIn.getPosX() + gTextureCheckIn.getWidth()) && (mPosY >= gTextureCheckIn.getPosY()) && (mPosY <= gTextureCheckIn.getPosY() + gTextureCheckIn.getHeight());
}

bool checkPlayAgain()
{
    // true = playagain, false = exit
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
                return false;
                break;

            case SDL_MOUSEMOTION:
                mousePosX = e.motion.x, mousePosY = e.motion.y;
                colorTextPlayAgain = colorWhite;
                colorTextExit = colorWhite;

                if (checkIn(mousePosX, mousePosY, gTextureTextPlayAgain))
                {
                    colorTextPlayAgain = colorYellow;
                }
                if (checkIn(mousePosX, mousePosY, gTextureTextExit))
                {
                    colorTextExit = colorYellow;
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                mousePosX = e.motion.x, mousePosY = e.motion.y;
                if (checkIn(mousePosX, mousePosY, gTextureTextPlayAgain))
                {
                    return true;
                }
                if (checkIn(mousePosX, mousePosY, gTextureTextExit))
                {
                    return false;
                }
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_SPACE)
                {
                    return true;
                }
                break;
            }
        }

        renderScreenGameOver();
    }
    return true;
}

bool checkGameOver()
{
    if (checkDead[0])
    {
        renderScreenGameOver();
        if (checkPlayAgain())
        {
            reset();

            gTextureTextGameOver.free();
            gTextureTextPlayAgain.free();
            gTextureTextExit.free();

            return false;
        }
        gTextureTextGameOver.free();
        gTextureTextPlayAgain.free();
        gTextureTextExit.free();
        return true;
    }
    gTextureTextGameOver.free();
    gTextureTextPlayAgain.free();
    gTextureTextExit.free();
    return false;
}