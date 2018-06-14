#include "global.h"
#include "units.h"

namespace units {
  bool visible = true;

  uint8_t *images[] = {
    soldierAImagePlusMask,
    soldierBImagePlusMask,
  };
  
  int all[] = {
    // x, y, image, selected
    // Soldier 1
    0, 1, 0, 0,
    // Soldier 2
    7, 2, 1, 0,
  };
  
  int getUnitXPosition (int index) {
    return all[index * UNIT_DATA_SIZE + UNIT_X_POSITION_INDEX];
  }

  int getUnitYPosition (int index) {
    return all[index * UNIT_DATA_SIZE + UNIT_Y_POSITION_INDEX];
  }

  int getUnitImageIndex (int index) {
    return all[index * UNIT_DATA_SIZE + UNIT_IMAGE_INDEX];
  }

  bool isUnitSelected (int index) {
    return all[index * UNIT_DATA_SIZE + UNIT_SELECTED_INDEX];
  }

  void setUnitPosition (int index, int x, int y) {
    all[index * UNIT_DATA_SIZE + UNIT_X_POSITION_INDEX] = x;
    all[index * UNIT_DATA_SIZE + UNIT_Y_POSITION_INDEX] = y;
  }

  int getSelectedUnit () {
    int unitIndex = -1;
    
    for (int index = 0; index < UNIT_COUNT; index++) {
      if (isUnitSelected(index)) {
        unitIndex = index;
      }
    }

    return unitIndex;
  }

  int getUnitAtPosition (int x, int y) {
    int unitIndex = -1;
    
    for (int index = 0; index < UNIT_COUNT; index++) {
      if (x == getUnitXPosition(index) && y == getUnitYPosition(index)) {
        unitIndex = index;
      }
    }

    return unitIndex;
  }

  void selectUnit (int index) {
    all[index * UNIT_DATA_SIZE + UNIT_SELECTED_INDEX] = 1;
  }

  void deselectUnit (int index) {
    all[index * UNIT_DATA_SIZE + UNIT_SELECTED_INDEX] = 0;
  }
  
  void hideUnits () {
    visible = false;
  }

  void showUnits () {
    visible = true;
  }
  
  void draw () {
    for (int index = 0; index < UNIT_COUNT; index++) {
      sprites.drawPlusMask(
        getUnitXPosition(index) * GRID_SIZE,
        getUnitYPosition(index) * GRID_SIZE - (isUnitSelected(index) ? 4 : 0),
        images[getUnitImageIndex(index)],
        0
      );      
    }
  }
  
  void loop () {
    if (visible) {
      draw();
    }
  }
}
