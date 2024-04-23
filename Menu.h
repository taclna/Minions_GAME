#pragma once
#include "ALL.h"
#include "Characters.h"
#include "Reset.h"
#include "GameOver.h"
#include "Texture.h"
#include "TimeAndLevel.h"

extern TTF_Font *gFontMenu;

extern LTexture gTextPlayTexture;
extern LTexture gTextHowToPlayTexture;
extern LTexture gTextExitTextureMenu;

int checkMouseMenu();
int showHowToPlay();
void showMenu();
void freeMenu();