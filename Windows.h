#pragma once
#include "ALL.h"
#include "Texture.h"
// The dimensions of the level
// Starts up SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();
