#pragma once
#include "ALL.h"
#include "Characters.h"
extern rectLevel Character[1000];
extern bool checkDead[1000];
bool checkCollision(SDL_Rect a, SDL_Rect b);
void checkCharactersCollision();
