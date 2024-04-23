#pragma once

#include "ALL.h"
#include "Texture.h"

extern Uint32 timeStartedGame;
extern Uint32 nowTimeChoosedThreat;
extern Uint32 nowTimeCoolDownSkill;

extern LTexture gTimeTextTexture;
extern LTexture gLevelTextTexture;

extern Uint32 timeChooseThreat;
extern Uint32 timeCoolDownSkill;

extern int levelMinions;
extern Uint32 YEAR, oldYEAR;

extern TTF_Font *gFontTextTimeLevel;

void renderTimeLevel();
void setLevel();
void freeTimeAndLevel();
