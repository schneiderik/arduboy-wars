#include "global.h"
#include "mainMenu.h"

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(FPS);
  arduboy.clear();
}

void loop() {
  if ((!arduboy.nextFrame())) return;

  arduboy.pollButtons();
  arduboy.clear();
  
  mainMenu::loop();
  
  arduboy.display();
}
