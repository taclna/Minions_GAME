#pragma once
#include "ALL.h"
#include "Characters.h"
extern bool checkDead[1000];

bool checkCollision(SDL_Rect a, SDL_Rect b);
void checkCharactersCollision();
bool checkDeadCollision(rectLevel a, rectLevel b);
