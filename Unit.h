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
    
class Unit {
  Position position;
  int type;
  uint8_t *image;
  bool selected;
    
  public:
    Unit() {};
  
    Unit(int vtype, Position vposition) : type(vtype), position(vposition), selected(false) {
      uint8_t *images[] = {
        soldierAImagePlusMask,
        soldierBImagePlusMask,
      };
  
      image = images[type];
    }
    
    void draw() {
      sprites.drawPlusMask(
        position.x * GRID_SIZE,
        position.y * GRID_SIZE - (selected ? 4 : 0),
        image,
        0
      ); 
    }
  
    void select() {
      selected = true;
    }
  
    void deselect() {
      selected = false;
    }

    bool isSelected () {
      return selected;
    }

    Position getPosition () {
      return position;
    }

    void setPosition (Position newPosition) {
      position = newPosition;
    }
  
    bool canMoveToPosition (Position newPosition) {
      return true;
    }
};

#endif
