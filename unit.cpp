#include "global.h"
#include "units.h"

namespace units {
  bool visible = true;
  
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

  void hide () {
    visible = false;
  }

  void show () {
    visible = true;
  }
  
  void loop () {
    if (visible) {
      draw();
    }
  }
}
