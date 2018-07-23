#ifndef COMMON_H_
#define COMMON_H_

#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<stdlib.h>
#include <ctime>
#include <fstream>
const int s_width=450;
const int s_height=800;

const int h_main=1;
const int w_main=30;

const int w_monster=23;
const int h_monster=23;

const int w_monster_boss=85;
const int h_monster_boss=246;

const int main_die=30;
const int fame=10;

const int boss_die=32;
const int boss_fame=7;

void timenull();

int makerand(int val);

bool checkcollision(SDL_Rect object1,SDL_Rect object2);
const int monster_=5;

static Mix_Chunk* bullet_shoot=NULL;
static Mix_Chunk* enemy1_down=NULL;
static Mix_Music* b_music=NULL;
static Mix_Chunk* dead=NULL;
static Mix_Chunk* boss_come=NULL;
static Mix_Chunk* enemy2_down=NULL;
static Mix_Chunk* get_pow=NULL;
#endif // COMMON_H_
