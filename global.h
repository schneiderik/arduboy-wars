#ifndef GLOBAL_H
#define GLOBAL_H

#define FPS 60
#define SCREEN_HEIGHT 64
#define SCREEN_WIDTH 128
#define GRID_SIZE 16
#define GRID_HEIGHT SCREEN_HEIGHT/GRID_SIZE
#define GRID_WIDTH SCREEN_WIDTH/GRID_SIZE
#define GRID_X_MAX GRID_WIDTH - 1
#define GRID_Y_MAX GRID_HEIGHT - 1

#include <Arduboy2.h>
#include <ArduboyTones.h>

typedef void (*FunctionPointer) ();

extern Arduboy2Base arduboy;
extern Sprites sprites;
extern ArduboyTones sound;
extern FunctionPointer currentLoop;

void navigateTo (FunctionPointer fp);

bool upJustPressed ();
bool downJustPressed ();
bool leftJustPressed ();
bool rightJustPressed ();
bool dPadJustPressed ();
bool aJustPressed ();
bool bJustPressed ();
bool buttonJustPressed ();

bool upPressed ();
bool downPressed ();
bool leftPressed ();
bool rightPressed ();
bool dPadPressed ();
bool aPressed ();
bool bPressed ();
bool buttonPressed ();

bool upJustReleased ();
bool downJustReleased ();
bool leftJustReleased ();
bool rightJustReleased ();
bool aJustReleased ();
bool bJustReleased ();

#endif
