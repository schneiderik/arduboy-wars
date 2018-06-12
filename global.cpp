#include "global.h"

Arduboy2Base arduboy;
Sprites sprites;
ArduboyTones sound(arduboy.audio.enabled);

void toggleSound() {
  if (arduboy.audio.enabled()) {
    arduboy.audio.off();
  } else {
    arduboy.audio.on();
  }

  arduboy.audio.saveOnOff();
}

bool upPressed () { return arduboy.justPressed(UP_BUTTON); }
bool downPressed () { return arduboy.justPressed(DOWN_BUTTON); }
bool leftPressed () { return arduboy.justPressed(LEFT_BUTTON); }
bool rightPressed () { return arduboy.justPressed(RIGHT_BUTTON); }
bool dPadPressed () { return upPressed() or downPressed() or leftPressed() or rightPressed(); }
bool aPressed () { return arduboy.justPressed(A_BUTTON); }
bool bPressed () { return arduboy.justPressed(B_BUTTON); }
bool buttonPressed() { return aPressed() or bPressed(); }
