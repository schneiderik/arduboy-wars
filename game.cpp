#include "global.h"
#include "game.h"
#include "cursor.h"
#include "gameMap.h"
#include "units.h"

namespace game {
  void draw () {
  }

  void update () {
    int unit;
    
    if (aJustPressed()) {
      unit = units::atPosition(cursor::x, cursor::y);
      
      if (unit >= 0) {
        units::select(unit);
      } else {
        units::hide();
      }
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
