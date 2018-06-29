#include "global.h"
#include "game.h"
#include "cursor.h"
#include "gameMap.h"
#include "units.h"
#include "Unit.h"

namespace game {
  void draw () {
  }

  void update () {      
    if (aJustPressed()) {
      if (units::unitIsCurrentlySelected()) {
        Unit* selectedUnit = units::getSelectedUnit();
        
        if (selectedUnit->canMoveToPosition(cursor::position)) {
          selectedUnit->setPosition(cursor::position);
          selectedUnit->deselect();
        }
      } else {
        if (units::unitExistsAtPosition(cursor::position)) {
          Unit* unitAtCursorPosition = units::getUnitAtPosition(cursor::position);
          
          unitAtCursorPosition->select();
        } else {
          units::hide();
        }
      }
    }

    if (bJustPressed()) {
      if (units::unitIsCurrentlySelected()) {
        Unit* selectedUnit = units::getSelectedUnit();
        
        selectedUnit->deselect();
      }
    }
    
    if (aJustReleased()) {
      units::show();
    }
  }
  
  void loop () {
    update();
    
    gameMap::loop();
    draw();
    units::loop();
    cursor::loop();    
  }
}
