#include "global.h"
#include "game.h"
#include "cursor.h"
#include "gameMap.h"

namespace game {
  void draw () {
    sprites.drawPlusMask(
      SOLDIER_A_X * GRID_SIZE,
      SOLDIER_A_Y * GRID_SIZE,
      soldierAImagePlusMask,
      0
    );
    
    sprites.drawPlusMask(
      SOLDIER_B_X * GRID_SIZE,
      SOLDIER_B_Y * GRID_SIZE,
      soldierBImagePlusMask,
      0
    );
  }
  
  void update () {
  }
  
  void loop () {
    gameMap::loop();
    
    draw();
    
    cursor::loop();
  }
}
