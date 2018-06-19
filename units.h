#ifndef UNITS_H
#define UNITS_H

#define UNIT_TEMPLATE_DATA_SIZE 3
#define UNIT_TEMPLATE_TYPE_INDEX 0
#define UNIT_TEMPLATE_POSITION_X_INDEX 1
#define UNIT_TEMPLATE_POSITION_Y_INDEX 2

#define UNIT_TYPE_DATA_SIZE 1
#define UNIT_TYPE_RANGE_INDEX 0

#define SOLDIER_RANGE 2

#include "Position.h"
#include "Unit.h"

namespace units {
  void loop();
  void build();
  bool unitExistsAtPosition(Position);
  bool unitIsCurrentlySelected();
  Unit* getUnitAtPosition(Position);
  Unit* getSelectedUnit();
  void hide();
  void show();
}

#endif
