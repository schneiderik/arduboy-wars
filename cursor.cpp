#include "global.h"
#include "cursor.h"
#include "Position.h"

namespace cursor {
  Position position = Position(CURSOR_DEFAULT_X, CURSOR_DEFAULT_Y);

  void update () {
    if (upJustPressed() and position.y > 0) {position.y--;}
    if (downJustPressed() and position.y < GRID_Y_MAX) {position.y++;}
    if (leftJustPressed() and position.x > 0) {position.x--;}
    if (rightJustPressed() and position.x < GRID_X_MAX) {position.x++;}
  }
  
  void draw() {
    sprites.drawPlusMask(
      position.x * GRID_SIZE,
      position.y * GRID_SIZE,
      cursorImagePlusMask,
      0
    );
  }

  void loop () {
    update();
    draw();
  }
}
