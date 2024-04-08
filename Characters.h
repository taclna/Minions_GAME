#pragma once
#include "ALL.h"
#include "Dot.h"
#include "Threat.h"
#include "ThreatRedFish.h"

const int maxNUM_RED_FISH = 100;
const int maxNUM_BLUE_FISH = 100;
extern int NUM_RED_FISH;
extern int NUM_BLUE_FISH;

void setNumThreat();
void charactersMove();
void charactersRender();

extern Dot dot;
extern Threat BlueFish[maxNUM_BLUE_FISH];
extern ThreatRedFish RedFish[maxNUM_RED_FISH];