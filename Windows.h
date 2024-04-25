#pragma once
#include "ALL.h"
#include "Texture.h"
#include "TimeAndLevel.h"
#include "GameOver.h"
#include "Menu.h"
#include "GameWin.h"

// The dimensions of the level
// Starts up SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();
