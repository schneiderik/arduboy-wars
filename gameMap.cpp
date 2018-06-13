#include "global.h"
#include "gameMap.h"

namespace gameMap {
  void draw() {
    for (int x = 0; x < GRID_WIDTH; x++) {
      for (int y = 0; y < GRID_HEIGHT; y++) {
        sprites.drawPlusMask(
          x * GRID_SIZE,
          (y * GRID_SIZE) - GAME_MAP_TILE_OFFSET,
          grassImagePlusMask,
          0
        );
      }
    }
  }

  void loop () {
    draw();
  }
}
