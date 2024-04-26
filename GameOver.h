#pragma once
#include "ALL.h"
#include "Collision.h"
#include "Windows.h"
#include "Reset.h"
#include "TimeAndLevel.h"

extern TTF_Font *gFontTextGameOver;
extern TTF_Font *gFontTextMenu;

extern LTexture gTextureTextGameOver;
extern LTexture gTextureTextPlayAgain;
extern LTexture gTextureTextExit;

bool checkIn(int &mPosX, int &mPosY, LTexture &gTextureCheckIn);
bool checkGameOver();
bool checkPlayAgain();
void freeGameOver();