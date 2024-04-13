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

extern int levelMinions;

extern SDL_Window *gWindow;

// The window renderer
extern SDL_Renderer *gRenderer;

extern TTF_Font *gFontTextLevel;

extern SDL_Color colorRed;
extern SDL_Color colorYellow;

extern int NUM_MINIONS_CHOOSE;

struct rectLevel
{
    SDL_Rect location;
    int level;
    SDL_RendererFlip Flip;

    rectLevel()
    {
        location = {0, 0, 0, 0};
        level = 0;
        Flip = SDL_FLIP_NONE;
    }

    rectLevel(SDL_Rect mLocation, int mLevel, SDL_RendererFlip mFlip)
    {
        location = mLocation;
        level = mLevel;
        Flip = mFlip;
    }
};
