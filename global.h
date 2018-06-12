#ifndef GLOBAL_H
#define GLOBAL_H

#define FPS 60

#include <Arduboy2.h>
#include <ArduboyTones.h>

typedef void (*FunctionPointer) ();

extern Arduboy2Base arduboy;
extern Sprites sprites;
extern ArduboyTones sound;
extern FunctionPointer currentLoop;

void navigateTo (FunctionPointer fp);
void toggleSound ();
bool upPressed ();
bool downPressed ();
bool leftPressed ();
bool rightPressed ();
bool dPadPressed ();
bool aPressed ();
bool bPressed ();
bool buttonPressed ();

#endif
