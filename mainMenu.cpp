#include "global.h"
#include "mainMenu.h"

namespace mainMenu {
  void drawMainTitle () {
    sprites.drawOverwrite(
      MAIN_TITLE_X,
      MAIN_TITLE_Y,
      titleImage,
      0
    );
  }

  void draw () {
    drawMainTitle();
  }
  
  void update () { 
  }
  
  void loop () {
    update();
    draw();
  }
}
