#ifndef GLOBAL_H
#define GLOBAL_H

#include <Arduboy2.h>
#include <ArduboyTones.h>

#define FPS 60

extern Arduboy2Base arduboy;
extern Sprites sprites;
extern ArduboyTones sound;

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
