#ifndef UNITS_H
#define UNITS_H

#define UNIT_DATA_SIZE 4
#define UNIT_X_POSITION_INDEX 0
#define UNIT_Y_POSITION_INDEX 1
#define UNIT_IMAGE_INDEX 2
#define UNIT_SELECTED_INDEX 3

#define UNIT_COUNT 2

namespace units {
  void loop();
  int atPosition(int, int);
  void select(int);
  void deselect(int);
  void hide();
  void show();

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
}

#endif
