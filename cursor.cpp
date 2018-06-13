#include "global.h"
#include "cursor.h"

namespace cursor {
  int x = CURSOR_DEFAULT_X;
  int y = CURSOR_DEFAULT_Y;

  void update () {
    if (upPressed() and y > 0) {y--;}
    if (downPressed() and y < GRID_Y_MAX) {y++;}
    if (leftPressed() and x > 0) {x--;}
    if (rightPressed() and x < GRID_X_MAX) {x++;}  
  }
  
  void draw() {
    sprites.drawPlusMask(
      x * GRID_SIZE,
      y * GRID_SIZE,
      cursorImagePlusMask,
      0
    );
  }

  void loop () {
    update();
    draw();
  }
}
