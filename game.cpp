#include "global.h"
#include "game.h"
#include "cursor.h"

namespace game {
  void draw () {
    sprites.drawPlusMask(
      SOLDIER_A_X,
      SOLDIER_A_Y,
      soldierAImagePlusMask,
      0
    );
    
    sprites.drawPlusMask(
      SOLDIER_B_X,
      SOLDIER_B_Y,
      soldierBImagePlusMask,
      0
    );
  }
  
  void update () {
  }
  
  void loop () {
    cursor::loop();
    
    draw();
  }
}
