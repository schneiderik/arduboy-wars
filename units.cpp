#include "global.h"
#include "units.h"
#include "Position.h"
#include "Unit.h"

namespace units {
  bool visible = true;
  const int unitCount = 4;

  enum UnitTypes {
    SoldierA,
    SoldierB
  };

  int unitTemplate[] {
    SoldierA, 0, 1,
    SoldierA, 1, 2,
    SoldierB, 7, 2,
    SoldierB, 6, 1,
  };

  Unit * all[unitCount];

  void build () {
    for (int i = 0; i < unitCount; i++) {
      int templateIndex = (i * UNIT_TEMPLATE_DATA_SIZE);
      int unitType = unitTemplate[templateIndex + UNIT_TEMPLATE_TYPE_INDEX];
      int unitPositionX = unitTemplate[templateIndex + UNIT_TEMPLATE_POSITION_X_INDEX];
      int unitPositionY = unitTemplate[templateIndex + UNIT_TEMPLATE_POSITION_Y_INDEX];
      
      all[i] = new Unit(unitType, Position(unitPositionX, unitPositionY));
    };
  }

  void update () {
    for (int index = 0; index < unitCount; index++) {
      all[index]->update();
    }   
  }
  
  bool unitIsCurrentlySelected () {
    for (int index = 0; index < unitCount; index++) {
      if (all[index]->isSelected()) {
        return true;
      }
    }  

    return false;
  }
  
  Unit* getSelectedUnit () {
    for (int index = 0; index < unitCount; index++) {
      if (all[index]->isSelected()) {
        return all[index];
      }
    }
  }

  bool unitExistsAtPosition (Position position) {
    for (int index = 0; index < unitCount; index++) {
      if (all[index]->getPosition() == position) {
        return true;
      }
    }

    return false;
  }

  Unit* getUnitAtPosition (Position position) {
    for (int index = 0; index < unitCount; index++) {
      if (all[index]->getPosition() == position) {
        return all[index];
      }
    }
  }

  void hide () {
    visible = false;
  }

  void show () {
    visible = true;
  }
  
  void draw () {
    for (int index = 0; index < unitCount; index++) {
      all[index]->draw();    
    }
  }
  
  void loop () {
    if (visible) {
      draw();
    }
  }
}
