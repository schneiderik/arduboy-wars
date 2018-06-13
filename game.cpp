#include "global.h"
#include "game.h"
#include "cursor.h"
#include "gameMap.h"
#include "units.h"

namespace game {
  void draw () {
  }

  void update () {
    if (aPressed()) {
      units::hide();
    }
    
    if (aJustReleased()) {
      units::show();
    }
  }
  
  void loop () {
    update();
    
    gameMap::loop();
    units::loop();
    cursor::loop();
  }
}
