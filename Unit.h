#ifndef UNIT_H 
#define UNIT_H 

PROGMEM const uint8_t soldierAImagePlusMask[] = {
  16, 16,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xfc, 0xfc, 0x46, 0xfe, 0xba, 0xfe, 0x3a, 0xfe, 
  0x5a, 0xfe, 0x5a, 0xfe, 0x92, 0xfe, 0xe6, 0xfe, 0x3c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0c, 0x0f, 0x3b, 0x3f, 0x22, 0x3f, 0x20, 0x3f, 
  0x22, 0x3f, 0x20, 0x3f, 0x2a, 0x3f, 0x3d, 0x3f, 0x05, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00,
};

PROGMEM const uint8_t soldierBImagePlusMask[] = {
  16, 16,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x3c, 0xe6, 0xfe, 0x82, 0xfe, 0x62, 0xfe, 0x62, 0xfe, 
  0x02, 0xfe, 0x82, 0xfe, 0x46, 0xfe, 0xfc, 0xfc, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x05, 0x07, 0x3d, 0x3f, 0x2a, 0x3f, 0x20, 0x3f, 0x22, 0x3f, 
  0x20, 0x3f, 0x22, 0x3f, 0x3b, 0x3f, 0x0c, 0x0f, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

PROGMEM const uint8_t accessiblePositionImagePlusMask[] = {
  16, 16,
  0x00, 0x22, 0x00, 0x11, 0x00, 0x88, 0x00, 0x44, 0x00, 0x22, 0x00, 0x11, 0x00, 0x88, 0x00, 0x44, 
  0x00, 0x22, 0x00, 0x11, 0x00, 0x88, 0x00, 0x44, 0x00, 0x22, 0x00, 0x11, 0x00, 0x88, 0x00, 0x44, 
  0x00, 0x22, 0x00, 0x11, 0x00, 0x88, 0x00, 0x44, 0x00, 0x22, 0x00, 0x11, 0x00, 0x88, 0x00, 0x44, 
  0x00, 0x22, 0x00, 0x11, 0x00, 0x88, 0x00, 0x44, 0x00, 0x22, 0x00, 0x11, 0x00, 0x88, 0x00, 0x44,
};
    
class Unit {
  Position position;
  Position accessiblePositions[20];
  int accessiblePositionIndex;
  int type;
  uint8_t *image;
  bool selected;
  int range;
    
  public:
    Unit() {};
    Unit(int vtype, Position vposition);

    void draw();
    void addAccessiblePositions(Position, int);
    void clearAccessiblePositions();
    Position updateAccessiblePositions();
    void drawMovementRange();
    void select();
    void deselect();
    bool isSelected();
    Position getPosition();
    void setPosition (Position);
    bool canMoveToPosition (Position);
};

#endif
