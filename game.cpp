#include "global.h"
#include "game.h"
#include "cursor.h"
#include "gameMap.h"
#include "units.h"
#include "Unit.h"

namespace game {
  void update () {
    if (units::unitIsCurrentlySelected()) {
      Unit* selectedUnit = units::getSelectedUnit();
      
      if (bJustPressed()) {        
        if (selectedUnit->canMoveToPosition(cursor::position)) {
          selectedUnit->setPosition(cursor::position);
          selectedUnit->deselect();
        }
      }
      
      if (aJustPressed()) {
        selectedUnit->deselect();
      }

      return;
    }

    if (units::unitExistsAtPosition(cursor::position)) {
      Unit* unitAtCursorPosition = units::getUnitAtPosition(cursor::position);
      
      if (bJustPressed()) {
        unitAtCursorPosition->select();
      }

      return;
    }
    
    if (bJustPressed()) {
      units::hide();
    }
    
    if (bJustReleased()) {
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
