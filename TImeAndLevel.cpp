#include "TimeAndLevel.h"

Uint32 timeStartedGame = 0;
Uint32 nowTimeCoolDownSkill = 0;

LTexture gTimeTextTexture;
LTexture gLevelTextTexture;
LTexture gCoolDownTexture;

Uint32 timeCoolDownSkill = 20000;

int levelMinions = 0;
Uint32 YEAR = 0;
Uint32 oldYEAR = YEAR;

TTF_Font *gFontTextTimeLevel = NULL;

SDL_Color colorCooldown = colorRed;

void setLevel()
{
    if (YEAR != oldYEAR)
    {
        levelMinions += 2;
        oldYEAR = YEAR;
    }
}
void renderTimeLevel()
{
    gFontTextTimeLevel = TTF_OpenFont("Data/Font/Nihonium113.ttf", 35);

    stringstream timeText;
    stringstream levelText;
    stringstream cooldownText;

    timeText.str("");
    levelText.str("");
    cooldownText.str("");

    YEAR = (SDL_GetTicks() - timeStartedGame) / 5000;
    Uint32 COOLDOWN = (timeCoolDownSkill - SDL_GetTicks() + nowTimeCoolDownSkill) / 1000;
    if (!(COOLDOWN >= 0 && COOLDOWN <= timeCoolDownSkill / 1000))
        COOLDOWN = 0;

    if (SDL_GetTicks() - nowTimeCoolDownSkill >= timeCoolDownSkill)
    {
        colorCooldown = colorGreen;
    }
    else
    {
        colorCooldown = colorRed;
    }

    timeText << "YEAR: " << YEAR;
    levelText << "LEVEL: " << levelMinions;
    cooldownText << "COOLDOWN: " << COOLDOWN << "s";

    if (!gTimeTextTexture.loadFromRenderedText(gFontTextTimeLevel, timeText.str().c_str(), colorWhite))
    {
        cout << "khong load duoc time text texture";
    }
    if (!gLevelTextTexture.loadFromRenderedText(gFontTextTimeLevel, levelText.str().c_str(), colorWhite))
    {
        cout << "khong load duoc level text texture";
    }
    if (!gCoolDownTexture.loadFromRenderedText(gFontTextTimeLevel, cooldownText.str().c_str(), colorCooldown))
    {
        cout << "khong load duoc level text texture";
    }

    gTimeTextTexture.render(640, 13);
    gLevelTextTexture.render(gTimeTextTexture.getPosX() + gTimeTextTexture.getWidth() + 30, gTimeTextTexture.getPosY());
    gCoolDownTexture.render(gLevelTextTexture.getPosX() + gLevelTextTexture.getWidth() + 30, gLevelTextTexture.getPosY());
}

void freeTimeAndLevel()
{
    gTimeTextTexture.free();
    gLevelTextTexture.free();
    gCoolDownTexture.free();

    gFontTextTimeLevel = NULL;
}