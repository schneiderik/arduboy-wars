#include "global.h"
#include "game.h"
#include "cursor.h"
#include "gameMap.h"
#include "units.h"

namespace game {
  void draw () {
  }

  void update () {
    int unitAtCursorPosition;
    int selectedUnit;
    
    if (aJustPressed()) {
      unitAtCursorPosition = units::getUnitAtPosition(cursor::x, cursor::y);
      selectedUnit = units::getSelectedUnit();

      if (selectedUnit >= 0) {
        units::setUnitPosition(selectedUnit, cursor::x, cursor::y);
        units::deselectUnit(selectedUnit);
      } else {
        if (unitAtCursorPosition >= 0) {
          units::selectUnit(unitAtCursorPosition);
        } else {
          units::hideUnits();
        }
      }
    }
    
    if (aJustReleased()) {
      units::showUnits();
    }
  }
  
  void loop () {
    update();
    
    gameMap::loop();
    units::loop();
    cursor::loop();
  }
}
