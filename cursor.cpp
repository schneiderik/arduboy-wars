#include "global.h"
#include "cursor.h"

namespace cursor {
  int x = CURSOR_DEFAULT_X;
  int y = CURSOR_DEFAULT_Y;

  void update () {
    if (upPressed() and y > 0) {
      y -= CURSOR_INCREMENT; 
    }
    if (downPressed() and y < SCREEN_HEIGHT - CURSOR_INCREMENT) {
      y += CURSOR_INCREMENT;
    }
    if (leftPressed() and x > 0) {
      x -= CURSOR_INCREMENT; 
    }
    if (rightPressed() and x < SCREEN_WIDTH - CURSOR_INCREMENT) {
      x += CURSOR_INCREMENT;
    }  
  }
  
  void draw() {
    sprites.drawPlusMask(
      x,
      y,
      cursorImagePlusMask,
      0
    );
  }

  void loop () {
    update();
    draw();
  }
}
