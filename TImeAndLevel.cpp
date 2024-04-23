#include "TimeAndLevel.h"

Uint32 timeStartedGame = 0;
Uint32 nowTimeChoosedThreat;
Uint32 nowTimeCoolDownSkill;

LTexture gTimeTextTexture;
LTexture gLevelTextTexture;

Uint32 timeCoolDownSkill = 5000;
Uint32 timeChooseThreat = 5000;

int levelMinions = 0;
Uint32 YEAR = 0;
Uint32 oldYEAR = YEAR;

TTF_Font *gFontTextTimeLevel = NULL;

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

    timeText.str("");
    levelText.str("");

    YEAR = (SDL_GetTicks() - timeStartedGame) / 10000;

    timeText << "YEAR: " << YEAR;
    levelText << "LEVEL: " << levelMinions;

    if (!gTimeTextTexture.loadFromRenderedText(gFontTextTimeLevel, timeText.str().c_str(), colorWhite))
    {
        cout << "khong load duoc time text texture";
    }
    if (!gLevelTextTexture.loadFromRenderedText(gFontTextTimeLevel, levelText.str().c_str(), colorWhite))
    {
        cout << "khong load duoc level text texture";
    }

    gTimeTextTexture.render(700, 15);
    gLevelTextTexture.render(gTimeTextTexture.getPosX() + gTimeTextTexture.getWidth() + 30, gTimeTextTexture.getPosY());
}

void freeTimeAndLevel()
{
    gTimeTextTexture.free();
    gLevelTextTexture.free();

    gFontTextTimeLevel = NULL;
}