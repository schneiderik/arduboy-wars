#include "global.h"
#include "mainMenu.h"

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(FPS);

  navigateTo(mainMenu::loop);
    
  arduboy.clear();
}

void loop() {
  if ((!arduboy.nextFrame())) return;

  arduboy.pollButtons();
  arduboy.clear();
  
  currentLoop();
  
  arduboy.display();
}
