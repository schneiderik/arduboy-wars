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

FunctionPointer currentLoop;

void navigateTo (FunctionPointer fp) { currentLoop = fp; }

bool upJustPressed () { return arduboy.justPressed(UP_BUTTON); }
bool downJustPressed () { return arduboy.justPressed(DOWN_BUTTON); }
bool leftJustPressed () { return arduboy.justPressed(LEFT_BUTTON); }
bool rightJustPressed () { return arduboy.justPressed(RIGHT_BUTTON); }
bool dPadJustPressed () { return upJustPressed() or downJustPressed() or leftJustPressed() or rightJustPressed(); }
bool aJustPressed () { return arduboy.justPressed(A_BUTTON); }
bool bJustPressed () { return arduboy.justPressed(B_BUTTON); }
bool buttonJustPressed () { return aJustPressed() or bJustPressed(); }

bool upPressed () { return arduboy.pressed(UP_BUTTON); }
bool downPressed () { return arduboy.pressed(DOWN_BUTTON); }
bool leftPressed () { return arduboy.pressed(LEFT_BUTTON); }
bool rightPressed () { return arduboy.pressed(RIGHT_BUTTON); }
bool dPadPressed () { return upPressed() or downPressed() or leftPressed() or rightPressed(); }
bool aPressed () { return arduboy.pressed(A_BUTTON); }
bool bPressed () { return arduboy.pressed(B_BUTTON); }
bool buttonPressed () { return aPressed() or bPressed(); }

bool upJustReleased () { return arduboy.justReleased(UP_BUTTON); }
bool downJustReleased () { return arduboy.justReleased(DOWN_BUTTON); }
bool leftJustReleased () { return arduboy.justReleased(LEFT_BUTTON); }
bool rightJustReleased () { return arduboy.justReleased(RIGHT_BUTTON); }
bool aJustReleased () { return arduboy.justReleased(A_BUTTON); }
bool bJustReleased () { return arduboy.justReleased(B_BUTTON); }
