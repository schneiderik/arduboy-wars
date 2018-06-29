#include "global.h"
#include "units.h"
  
Unit::Unit(int vtype, Position vposition) : type(vtype), position(vposition), selected(false) {
  uint8_t *images[] = {
    soldierAImagePlusMask,
    soldierBImagePlusMask,
  };

  image = images[type];
  range = 2;
  updateAccessiblePositions();
}
    
void Unit::draw() {
  if (selected) {
    drawMovementRange();  
  }
  
  sprites.drawPlusMask(
    position.x * GRID_SIZE,
    position.y * GRID_SIZE,
    image,
    0
  ); 
}

void Unit::addAccessiblePositions(Position refPosition, int itterationIndex) {
  accessiblePositions[accessiblePositionIndex] = refPosition;

  if (itterationIndex < range) {
    itterationIndex++;
    
    Position west = Position(refPosition.x - 1, refPosition.y);
    Position east = Position(refPosition.x + 1, refPosition.y);
    Position north = Position(refPosition.x, refPosition.y - 1);
    Position south = Position(refPosition.x, refPosition.y + 1);

    bool canGoWest = refPosition.x > 0 && !units::unitExistsAtPosition(west);
    bool canGoEast = refPosition.x < GRID_X_MAX && !units::unitExistsAtPosition(east);
    bool canGoNorth = refPosition.y > 0 && !units::unitExistsAtPosition(north);
    bool canGoSouth = refPosition.y < GRID_Y_MAX && !units::unitExistsAtPosition(south);

    if (canGoWest) {
      accessiblePositionIndex++;
      addAccessiblePositions(west, itterationIndex);
    }
    if (canGoEast) {
      accessiblePositionIndex++;
      addAccessiblePositions(east, itterationIndex);
    }
    if (canGoNorth) {
      accessiblePositionIndex++;
      addAccessiblePositions(north, itterationIndex);
    }  
    if (canGoSouth) {
      accessiblePositionIndex++;
      addAccessiblePositions(south, itterationIndex);
    }
  }
}

Position Unit::updateAccessiblePositions() {
  accessiblePositionIndex = 0;

  addAccessiblePositions(position, 0);    
}

void Unit::drawMovementRange() {
  for (int i = 0; i < accessiblePositionIndex + 1; i++) {
    sprites.drawPlusMask(
      accessiblePositions[i].x * GRID_SIZE,
      accessiblePositions[i].y * GRID_SIZE,
      accessiblePositionImagePlusMask,
      0
    );
  }
}

void Unit::select() {
  updateAccessiblePositions();
  selected = true;
}

void Unit::deselect() {
  selected = false;
}

bool Unit::isSelected () {
  return selected;
}

Position Unit::getPosition () {
  return position;
}

void Unit::setPosition (Position newPosition) {
  position = newPosition;
}

bool Unit::canMoveToPosition (Position targetPosition) {
  for (int i = 0; i < accessiblePositionIndex + 1; i++) {
    if (accessiblePositions[i] == targetPosition) {
      return true;
    }
  }
  
  return false;
}
