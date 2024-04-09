#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <bits/stdc++.h>
using namespace std;
// The window we'll be rendering to

const int LEVEL_WIDTH = 1080;
const int LEVEL_HEIGHT = 756;

// Screen dimension constants
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 756;

extern SDL_Window *gWindow;

// The window renderer
extern SDL_Renderer *gRenderer;

struct rectLevel
{
    SDL_Rect location;
    int level;

    rectLevel()
    {
        location = {0, 0, 0, 0};
        level = 0;
    }

    rectLevel(SDL_Rect mLocation, int mLevel)
    {
        location = mLocation;
        level = mLevel;
    }
};
