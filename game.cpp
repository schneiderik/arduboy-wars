#include "global.h"
#include "game.h"
#include "cursor.h"
#include "gameMap.h"
#include "units.h"
#include "Unit.h"

namespace game {
  void addPositions(Position* positions, int* positionIndexPointer, int range, int* rangeIndexPointer, Position position) {
    (*rangeIndexPointer)++;
          
    Position west = Position(position.x - 1, position.y);
    Position east = Position(position.x + 1, position.y);
    Position north = Position(position.x, position.y - 1);
    Position south = Position(position.x, position.y + 1);

    bool canGoWest = position.x > 0 && !units::unitExistsAtPosition(west);
    bool canGoEast = position.x < GRID_X_MAX && !units::unitExistsAtPosition(east);
    bool canGoNorth = position.y > 0 && !units::unitExistsAtPosition(north);
    bool canGoSouth = position.y < GRID_Y_MAX && !units::unitExistsAtPosition(south);
    
    if (canGoWest) {
      (*positionIndexPointer)++;
      positions[*positionIndexPointer] = west;
    }

    if (canGoEast) {
      (*positionIndexPointer)++;
      positions[*positionIndexPointer] = east;
    }

    if (canGoNorth) {
      (*positionIndexPointer)++;
      positions[*positionIndexPointer] = north; 
    }

    if (canGoSouth) {
      (*positionIndexPointer)++;
      positions[*positionIndexPointer] = south;
    }     
   
    if ((*rangeIndexPointer) < range) {
      if (canGoWest) {
        addPositions(positions, positionIndexPointer, range, rangeIndexPointer, west);
      }
      if (canGoEast) {
        addPositions(positions, positionIndexPointer, range, rangeIndexPointer, east);
      }
      if (canGoNorth) {
        addPositions(positions, positionIndexPointer, range, rangeIndexPointer, north);
      }  
      if (canGoSouth) {
        addPositions(positions, positionIndexPointer, range, rangeIndexPointer, south);
      }      
    }
  }
  
  void draw () {
    if (units::unitIsCurrentlySelected()) {
      Unit* selectedUnit = units::getSelectedUnit();

      int range = 2;
      int rangeIndex = 0;
      int arrayIndex = 0;
      Position positions[20];
      Position unitPosition = selectedUnit->getPosition();

      positions[arrayIndex] = unitPosition;
      
      addPositions(positions, &arrayIndex, range, &rangeIndex, unitPosition);

      for (int i = 0; i < arrayIndex + 1; i++) {
        sprites.drawPlusMask(
          positions[i].x * GRID_SIZE,
          positions[i].y * GRID_SIZE,
          accessiblePositionImagePlusMask,
          0
        );
      }
    }
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
