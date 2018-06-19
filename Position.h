#ifndef POSITION_H 
#define POSITION_H 

struct Position {
  int x;
  int y;

  Position() : x(0), y(0) {}
  Position(int vx, int vy) : x(vx), y(vy) {}

  bool operator==(const Position& comparisonPosition) {
    return x == comparisonPosition.x && y == comparisonPosition.y;
  }
};

#endif
